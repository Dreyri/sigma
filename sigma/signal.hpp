#ifndef SIGMA_SIGNAL_HPP_INCLUDED
#define SIGMA_SIGNAL_HPP_INCLUDED

#pragma once

#include <functional>
#include <iterator>
#include <memory>
#include <mutex>

#include "sigma/connection.hpp"
#include "sigma/disconnector.hpp"
#include "sigma/dummy_mutex.hpp"
#include "sigma/function_ref.hpp"
#include "sigma/handle_vector.hpp"
#include "sigma/result.hpp"

namespace sigma
{
template<bool Nothrow, typename Signature>
struct signal_traits;

template<bool Nothrow, typename Ret, typename... Args>
struct signal_traits<Nothrow, Ret(Args...)>
{
    static constexpr bool is_nothrow = Nothrow;

    using return_type = Ret;

    using _base_signature_type = return_type(Args...);

    // read as sigma::function_ref<return_type(Args...) noexcept(is_nothrow)>
    using slot_type = sigma::function_ref<
        std::conditional_t<is_nothrow,
                           sigma::add_signature_nothrow_t<_base_signature_type>,
                           _base_signature_type>>;
};

template<typename Signature>
class signal final {
    static_assert(sigma::is_signature_v<Signature>,
                  "Provided Signature is not a valid function signature");

    static_assert(!sigma::is_signature_const_v<Signature>,
                  "Signature cannot have const qualifier");
    static_assert(!sigma::is_signature_volatile_v<Signature>,
                  "Signature cannot have volatile qualifier");
    static_assert(!sigma::is_signature_lvalue_v<Signature>,
                  "Signature cannot have lvalue qualifier");
    static_assert(!sigma::is_signature_rvalue_v<Signature>,
                  "Signature cannot have rvalue qualifier");

public:
    struct disconnector : public sigma::disconnector_base
    {
    private:
        std::reference_wrapper<sigma::signal<Signature>> m_signal;

    public:
        disconnector(sigma::signal<Signature>& signal) : m_signal{signal}
        {}

        bool is_alive(const connection& conn) const noexcept override
        {
            return m_signal.get().connection_alive(conn);
        }

        void operator()(sigma::connection& c) override
        {
            m_signal.get().disconnect(c);
        }
    };

    using return_type    = sigma::signature_return_t<Signature>;
    using signature_type = Signature;
    using slot_type      = sigma::function_ref<signature_type>;
    using container_type = sigma::handle_vector<slot_type>;
    using mutex_type     = sigma::dummy_mutex;

private:
    container_type m_slots;
    mutex_type     m_mutex;

    std::shared_ptr<disconnector> m_disconnector;

public:
    signal() : m_disconnector{std::make_shared<disconnector>(*this)}
    {}

    /**
     * call each slot
     */
    /*
    template<typename RetFn,
             typename ExcFn,
             typename... Args,
             typename = std::enable_if_t<
                 std::is_invocable_r_v<return_type, slot_type, Args&&...> &&
                 std::is_invocable_v<RetFn, return_type> &&
                 std::is_invocable_v<ExcFn, std::exception_ptr>>>
    void operator()(RetFn rfn, ExcFn efn, Args&&... args) noexcept
    {
        std::lock_guard lock{m_mutex};

        for (auto& slot : m_slots)
        {
            if constexpr (std::is_nothrow_invocable_v<slot_type, Args&&...>)
            {
                rfn(std::forward<return_type>(std::invoke(slot,
    std::forward<Args>(args)...));
            }
            else
            {
                try
                {
                    rfn(std::forward<return_type>(
                        std::invoke(slot, std::forward<Args>(args)...)));
                }
                catch (...)
                {
                    efn(std::current_exception());
                }
            }
        }
    }
    */

    template<typename... Args,
             typename = std::enable_if_t<
                 std::is_invocable_r_v<return_type, slot_type, Args&&...>>>
    void operator()(Args&&... args) noexcept(
        std::is_nothrow_invocable_v<slot_type, Args&&...>)
    {
        std::lock_guard lock{m_mutex};

        for (auto& slot : m_slots)
        {
            if constexpr (std::is_nothrow_invocable_v<slot_type, Args&&...>)
            {
                std::invoke(slot, std::forward<Args>(args)...);
            }
            else
            {
                try
                {
                    std::invoke(slot, std::forward<Args>(args)...);
                }
                catch (...)
                {
                    // efn(std::current_exception());
                }
            }
        }
    }

    template<typename... Args,
             typename = std::enable_if_t<!std::is_same_v<void, return_type>>>
    std::vector<sigma::result<return_type, slot_type::is_nothrow>>
    emit_accumulate(Args&&... args)
    {
        std::vector<sigma::result<return_type, slot_type::is_nothrow>>
            accumulator;
        accumulator.reserve(std::size(m_slots));

        (*this)(
            [&](return_type&& ret) {
                accumulator.emplace_back(std::forward<return_type>(ret));
            },
            [&](const std::exception_ptr& ptr) {
                accumulator.emplace_back(ptr);
            },
            std::forward<Args>(args)...);

        return accumulator;
    }

    template<typename... Args>
    sigma::connection connect(Args&&... args)
    {
        static_assert(
            std::is_constructible_v<typename container_type::value_type,
                                    Args&&...>,
            "Cannot construct function_ref from Args...");
        std::lock_guard lock{m_mutex};

        auto idx    = std::size(m_slots);
        auto handle = m_slots.emplace_back(std::forward<Args>(args)...);

        return sigma::connection{m_disconnector, handle};
    }

    bool connection_alive(const sigma::connection& c) const noexcept
    {
        return m_slots.is_valid_handle(c.handle());
    }

    /**
     * usually there's no need to call this function directly, disconnection
     * should be done through the connection's disconnect function
     */
    void disconnect(sigma::connection& c)
    {
        std::lock_guard lock{m_mutex};
        m_slots.erase(c.m_handle);
    }
};
} // namespace sigma

#endif