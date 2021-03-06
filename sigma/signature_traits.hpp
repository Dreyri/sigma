#ifndef SIGMA_SIGNATURE_TRAITS_HPP_INCLUDED
#define SIGMA_SIGNATURE_TRAITS_HPP_INCLUDED

#pragma once

#include "sigma/parameter_list.hpp"

namespace sigma
{
// add function qualifiers

template<typename Signature>
struct add_signature_variadic
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...)>
{
    using type = Ret(Args..., ...);
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const>
{
    using type = Ret(Args..., ...) const;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) volatile>
{
    using type = Ret(Args..., ...) volatile;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const volatile>
{
    using type = Ret(Args..., ...) const volatile;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...)&>
{
    using type = Ret(Args..., ...) &;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const&>
{
    using type = Ret(Args..., ...) const&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) volatile&>
{
    using type = Ret(Args..., ...) volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const volatile&>
{
    using type = Ret(Args..., ...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) &&>
{
    using type = Ret(Args..., ...) &&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const&&>
{
    using type = Ret(Args..., ...) const&&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) volatile&&>
{
    using type = Ret(Args..., ...) volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const volatile&&>
{
    using type = Ret(Args..., ...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) noexcept>
{
    using type = Ret(Args..., ...) noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const noexcept>
{
    using type = Ret(Args..., ...) const noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) volatile noexcept>
{
    using type = Ret(Args..., ...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const volatile noexcept>
{
    using type = Ret(Args..., ...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) & noexcept>
{
    using type = Ret(Args..., ...) & noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const& noexcept>
{
    using type = Ret(Args..., ...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) volatile& noexcept>
{
    using type = Ret(Args..., ...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const volatile& noexcept>
{
    using type = Ret(Args..., ...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) && noexcept>
{
    using type = Ret(Args..., ...) && noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const&& noexcept>
{
    using type = Ret(Args..., ...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) volatile&& noexcept>
{
    using type = Ret(Args..., ...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_variadic<Ret(Args...) const volatile&& noexcept>
{
    using type = Ret(Args..., ...) const volatile&& noexcept;
};

template<typename Signature>
using add_signature_variadic_t =
    typename add_signature_variadic<Signature>::type;

// add const qualifier

template<typename Signature>
struct add_signature_const
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...)>
{
    using type = Ret(Args...) const;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...)>
{
    using type = Ret(Args..., ...) const;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) volatile>
{
    using type = Ret(Args...) const volatile;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) volatile>
{
    using type = Ret(Args..., ...) const volatile;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...)&>
{
    using type = Ret(Args...) const&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...)&>
{
    using type = Ret(Args..., ...) const&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) volatile&>
{
    using type = Ret(Args...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) volatile&>
{
    using type = Ret(Args..., ...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) &&>
{
    using type = Ret(Args...) const&&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) &&>
{
    using type = Ret(Args..., ...) const&&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) volatile&&>
{
    using type = Ret(Args...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) volatile&&>
{
    using type = Ret(Args..., ...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) noexcept>
{
    using type = Ret(Args...) const noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) noexcept>
{
    using type = Ret(Args..., ...) const noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) volatile noexcept>
{
    using type = Ret(Args...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) volatile noexcept>
{
    using type = Ret(Args..., ...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) & noexcept>
{
    using type = Ret(Args...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) & noexcept>
{
    using type = Ret(Args..., ...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) volatile& noexcept>
{
    using type = Ret(Args...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) volatile& noexcept>
{
    using type = Ret(Args..., ...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) && noexcept>
{
    using type = Ret(Args...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) && noexcept>
{
    using type = Ret(Args..., ...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args...) volatile&& noexcept>
{
    using type = Ret(Args...) const volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_const<Ret(Args..., ...) volatile&& noexcept>
{
    using type = Ret(Args..., ...) const volatile&& noexcept;
};

template<typename Signature>
using add_signature_const_t = typename add_signature_const<Signature>::type;

// add volatile qualifier

template<typename Signature>
struct add_signature_volatile
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...)>
{
    using type = Ret(Args...) volatile;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...)>
{
    using type = Ret(Args..., ...) volatile;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) const>
{
    using type = Ret(Args...) const volatile;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) const>
{
    using type = Ret(Args..., ...) const volatile;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...)&>
{
    using type = Ret(Args...) volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...)&>
{
    using type = Ret(Args..., ...) volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) const&>
{
    using type = Ret(Args...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) const&>
{
    using type = Ret(Args..., ...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) &&>
{
    using type = Ret(Args...) volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) &&>
{
    using type = Ret(Args..., ...) volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) const&&>
{
    using type = Ret(Args...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) const&&>
{
    using type = Ret(Args..., ...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) noexcept>
{
    using type = Ret(Args...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) noexcept>
{
    using type = Ret(Args..., ...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) const noexcept>
{
    using type = Ret(Args...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) const noexcept>
{
    using type = Ret(Args..., ...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) & noexcept>
{
    using type = Ret(Args...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) & noexcept>
{
    using type = Ret(Args..., ...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) const& noexcept>
{
    using type = Ret(Args...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) const& noexcept>
{
    using type = Ret(Args..., ...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) && noexcept>
{
    using type = Ret(Args...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) && noexcept>
{
    using type = Ret(Args..., ...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args...) const&& noexcept>
{
    using type = Ret(Args...) const volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_volatile<Ret(Args..., ...) const&& noexcept>
{
    using type = Ret(Args..., ...) const volatile&& noexcept;
};

template<typename Signature>
using add_signature_volatile_t =
    typename add_signature_volatile<Signature>::type;

// add lvalue qualifier

template<typename Signature>
struct add_signature_lvalue
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...)>
{
    using type = Ret(Args...) &;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...)>
{
    using type = Ret(Args..., ...) &;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) const>
{
    using type = Ret(Args...) const&;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) const>
{
    using type = Ret(Args..., ...) const&;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) volatile>
{
    using type = Ret(Args...) volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) volatile>
{
    using type = Ret(Args..., ...) volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) const volatile>
{
    using type = Ret(Args...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) const volatile>
{
    using type = Ret(Args..., ...) const volatile&;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) noexcept>
{
    using type = Ret(Args...) & noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) noexcept>
{
    using type = Ret(Args..., ...) & noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) const noexcept>
{
    using type = Ret(Args...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) const noexcept>
{
    using type = Ret(Args..., ...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) volatile noexcept>
{
    using type = Ret(Args...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) volatile noexcept>
{
    using type = Ret(Args..., ...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args...) const volatile noexcept>
{
    using type = Ret(Args...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_lvalue<Ret(Args..., ...) const volatile noexcept>
{
    using type = Ret(Args..., ...) const volatile& noexcept;
};

template<typename Signature>
using add_signature_lvalue_t = typename add_signature_lvalue<Signature>::type;

// add rvalue qualifier

template<typename Signature>
struct add_signature_rvalue
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...)>
{
    using type = Ret(Args...) &&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...)>
{
    using type = Ret(Args..., ...) &&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) const>
{
    using type = Ret(Args...) const&&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) const>
{
    using type = Ret(Args..., ...) const&&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) volatile>
{
    using type = Ret(Args...) volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) volatile>
{
    using type = Ret(Args..., ...) volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) const volatile>
{
    using type = Ret(Args...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) const volatile>
{
    using type = Ret(Args..., ...) const volatile&&;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) noexcept>
{
    using type = Ret(Args...) && noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) noexcept>
{
    using type = Ret(Args..., ...) && noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) const noexcept>
{
    using type = Ret(Args...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) const noexcept>
{
    using type = Ret(Args..., ...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) volatile noexcept>
{
    using type = Ret(Args...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) volatile noexcept>
{
    using type = Ret(Args..., ...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args...) const volatile noexcept>
{
    using type = Ret(Args...) const volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_rvalue<Ret(Args..., ...) const volatile noexcept>
{
    using type = Ret(Args..., ...) const volatile&& noexcept;
};

template<typename Signature>
using add_signature_rvalue_t = typename add_signature_rvalue<Signature>::type;

// add nothrow qualifiers

template<typename Signature>
struct add_signature_nothrow
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...)>
{
    using type = Ret(Args...) noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...)>
{
    using type = Ret(Args..., ...) noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) const>
{
    using type = Ret(Args...) const noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) const>
{
    using type = Ret(Args..., ...) const noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) volatile>
{
    using type = Ret(Args...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) volatile>
{
    using type = Ret(Args..., ...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) const volatile>
{
    using type = Ret(Args...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) const volatile>
{
    using type = Ret(Args..., ...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...)&>
{
    using type = Ret(Args...) & noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...)&>
{
    using type = Ret(Args..., ...) & noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) const&>
{
    using type = Ret(Args...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) const&>
{
    using type = Ret(Args..., ...) const& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) volatile&>
{
    using type = Ret(Args...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) volatile&>
{
    using type = Ret(Args..., ...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) const volatile&>
{
    using type = Ret(Args...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) const volatile&>
{
    using type = Ret(Args..., ...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) &&>
{
    using type = Ret(Args...) && noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) &&>
{
    using type = Ret(Args..., ...) && noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) const&&>
{
    using type = Ret(Args...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) const&&>
{
    using type = Ret(Args..., ...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) volatile&&>
{
    using type = Ret(Args...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) volatile&&>
{
    using type = Ret(Args..., ...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args...) const volatile&&>
{
    using type = Ret(Args...) const volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct add_signature_nothrow<Ret(Args..., ...) const volatile&&>
{
    using type = Ret(Args..., ...) const volatile&& noexcept;
};

// specializations for noexcept(false) are not necessary in my opinion because
// remove_signature_nothrow already handles this functionality

template<typename Signature>
using add_signature_nothrow_t = typename add_signature_nothrow<Signature>::type;

// decay function qualifiers

template<typename Signature>
struct remove_signature_variadic
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...)>
{
    using type = Ret(Args...);
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const>
{
    using type = Ret(Args...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) volatile>
{
    using type = Ret(Args...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const volatile>
{
    using type = Ret(Args...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...)&>
{
    using type = Ret(Args...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const&>
{
    using type = Ret(Args...) const&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) volatile&>
{
    using type = Ret(Args...) volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const volatile&>
{
    using type = Ret(Args...) const volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) &&>
{
    using type = Ret(Args...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const&&>
{
    using type = Ret(Args...) const&&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) volatile&&>
{
    using type = Ret(Args...) volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const volatile&&>
{
    using type = Ret(Args...) const volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) noexcept>
{
    using type = Ret(Args...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const noexcept>
{
    using type = Ret(Args...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) volatile noexcept>
{
    using type = Ret(Args...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const volatile noexcept>
{
    using type = Ret(Args...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) & noexcept>
{
    using type = Ret(Args...) & noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const& noexcept>
{
    using type = Ret(Args...) const& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) volatile& noexcept>
{
    using type = Ret(Args...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const volatile& noexcept>
{
    using type = Ret(Args...) const volatile& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) && noexcept>
{
    using type = Ret(Args...) && noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const&& noexcept>
{
    using type = Ret(Args...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) volatile&& noexcept>
{
    using type = Ret(Args...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_variadic<Ret(Args..., ...) const volatile&& noexcept>
{
    using type = Ret(Args...) const volatile&& noexcept;
};

template<typename Signature>
using remove_signature_variadic_t =
    typename remove_signature_variadic<Signature>::type;

// removing const from signatures

template<typename Signature>
struct remove_signature_const
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const>
{
    using type = Ret(Args...);
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const>
{
    using type = Ret(Args..., ...);
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const volatile>
{
    using type = Ret(Args...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const volatile>
{
    using type = Ret(Args..., ...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const&>
{
    using type = Ret(Args...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const&>
{
    using type = Ret(Args..., ...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const volatile&>
{
    using type = Ret(Args...) volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const volatile&>
{
    using type = Ret(Args..., ...) volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const&&>
{
    using type = Ret(Args...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const&&>
{
    using type = Ret(Args..., ...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const volatile&&>
{
    using type = Ret(Args...) volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const volatile&&>
{
    using type = Ret(Args..., ...) volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const noexcept>
{
    using type = Ret(Args...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const noexcept>
{
    using type = Ret(Args..., ...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const volatile noexcept>
{
    using type = Ret(Args...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const volatile noexcept>
{
    using type = Ret(Args..., ...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const& noexcept>
{
    using type = Ret(Args...) & noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const& noexcept>
{
    using type = Ret(Args..., ...) & noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const volatile& noexcept>
{
    using type = Ret(Args...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const volatile& noexcept>
{
    using type = Ret(Args..., ...) volatile& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const&& noexcept>
{
    using type = Ret(Args...) && noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const&& noexcept>
{
    using type = Ret(Args..., ...) && noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args...) const volatile&& noexcept>
{
    using type = Ret(Args...) volatile&& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_const<Ret(Args..., ...) const volatile&& noexcept>
{
    using type = Ret(Args..., ...) volatile&& noexcept;
};

template<typename Signature>
using remove_signature_const_t =
    typename remove_signature_const<Signature>::type;

// remove volatile from signature

template<typename Signature>
struct remove_signature_volatile
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) volatile>
{
    using type = Ret(Args...);
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) volatile>
{
    using type = Ret(Args..., ...);
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) const volatile>
{
    using type = Ret(Args...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) const volatile>
{
    using type = Ret(Args..., ...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) volatile&>
{
    using type = Ret(Args...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) volatile&>
{
    using type = Ret(Args..., ...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) const volatile&>
{
    using type = Ret(Args...) const&;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) const volatile&>
{
    using type = Ret(Args..., ...) const&;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) volatile&&>
{
    using type = Ret(Args...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) volatile&&>
{
    using type = Ret(Args..., ...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) const volatile&&>
{
    using type = Ret(Args...) const&&;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) const volatile&&>
{
    using type = Ret(Args..., ...) const&&;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) volatile noexcept>
{
    using type = Ret(Args...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) volatile noexcept>
{
    using type = Ret(Args..., ...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) const volatile noexcept>
{
    using type = Ret(Args...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) const volatile noexcept>
{
    using type = Ret(Args..., ...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) volatile& noexcept>
{
    using type = Ret(Args...) & noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) volatile& noexcept>
{
    using type = Ret(Args..., ...) & noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) const volatile& noexcept>
{
    using type = Ret(Args...) const& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) const volatile& noexcept>
{
    using type = Ret(Args..., ...) const& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) volatile&& noexcept>
{
    using type = Ret(Args...) && noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) volatile&& noexcept>
{
    using type = Ret(Args..., ...) && noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args...) const volatile&& noexcept>
{
    using type = Ret(Args...) const&& noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_volatile<Ret(Args..., ...) const volatile&& noexcept>
{
    using type = Ret(Args..., ...) const&& noexcept;
};

template<typename Signature>
using remove_signature_volatile_t =
    typename remove_signature_volatile<Signature>::type;

// remove lvalue qualifier from signature

template<typename Signature>
struct remove_signature_lvalue
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...)&>
{
    using type = Ret(Args...);
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...)&>
{
    using type = Ret(Args..., ...);
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) const&>
{
    using type = Ret(Args...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) const&>
{
    using type = Ret(Args..., ...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) volatile&>
{
    using type = Ret(Args...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) volatile&>
{
    using type = Ret(Args..., ...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) const volatile&>
{
    using type = Ret(Args...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) const volatile&>
{
    using type = Ret(Args..., ...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) & noexcept>
{
    using type = Ret(Args...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) & noexcept>
{
    using type = Ret(Args..., ...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) const& noexcept>
{
    using type = Ret(Args...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) const& noexcept>
{
    using type = Ret(Args..., ...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) volatile& noexcept>
{
    using type = Ret(Args...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) volatile& noexcept>
{
    using type = Ret(Args..., ...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args...) const volatile& noexcept>
{
    using type = Ret(Args...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_lvalue<Ret(Args..., ...) const volatile& noexcept>
{
    using type = Ret(Args..., ...) const volatile noexcept;
};

template<typename Signature>
using remove_signature_lvalue_t =
    typename remove_signature_lvalue<Signature>::type;

// remove rvalue qualifier from signature

template<typename Signature>
struct remove_signature_rvalue
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) &&>
{
    using type = Ret(Args...);
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) &&>
{
    using type = Ret(Args..., ...);
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) const&&>
{
    using type = Ret(Args...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) const&&>
{
    using type = Ret(Args..., ...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) volatile&&>
{
    using type = Ret(Args...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) volatile&&>
{
    using type = Ret(Args..., ...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) const volatile&&>
{
    using type = Ret(Args...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) const volatile&&>
{
    using type = Ret(Args..., ...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) && noexcept>
{
    using type = Ret(Args...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) && noexcept>
{
    using type = Ret(Args..., ...) noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) const&& noexcept>
{
    using type = Ret(Args...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) const&& noexcept>
{
    using type = Ret(Args..., ...) const noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) volatile&& noexcept>
{
    using type = Ret(Args...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) volatile&& noexcept>
{
    using type = Ret(Args..., ...) volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args...) const volatile&& noexcept>
{
    using type = Ret(Args...) const volatile noexcept;
};

template<typename Ret, typename... Args>
struct remove_signature_rvalue<Ret(Args..., ...) const volatile&& noexcept>
{
    using type = Ret(Args..., ...) const volatile noexcept;
};

template<typename Signature>
using remove_signature_rvalue_t =
    typename remove_signature_rvalue<Signature>::type;

// remove noexcept qualifier from signature

template<typename Signature>
struct remove_signature_nothrow
{
    using type = Signature;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) noexcept>
{
    using type = Ret(Args...);
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) noexcept>
{
    using type = Ret(Args..., ...);
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) const noexcept>
{
    using type = Ret(Args...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) const noexcept>
{
    using type = Ret(Args..., ...) const;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) volatile noexcept>
{
    using type = Ret(Args...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) volatile noexcept>
{
    using type = Ret(Args..., ...) volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) const volatile noexcept>
{
    using type = Ret(Args...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) const volatile noexcept>
{
    using type = Ret(Args..., ...) const volatile;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) & noexcept>
{
    using type = Ret(Args...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) & noexcept>
{
    using type = Ret(Args..., ...) &;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) const& noexcept>
{
    using type = Ret(Args...) const&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) const& noexcept>
{
    using type = Ret(Args..., ...) const&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) volatile& noexcept>
{
    using type = Ret(Args...) volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) volatile& noexcept>
{
    using type = Ret(Args..., ...) volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) const volatile& noexcept>
{
    using type = Ret(Args...) const volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) const volatile& noexcept>
{
    using type = Ret(Args..., ...) const volatile&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) && noexcept>
{
    using type = Ret(Args...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) && noexcept>
{
    using type = Ret(Args..., ...) &&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) const&& noexcept>
{
    using type = Ret(Args...) const&&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) const&& noexcept>
{
    using type = Ret(Args..., ...) const&&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) volatile&& noexcept>
{
    using type = Ret(Args...) volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) volatile&& noexcept>
{
    using type = Ret(Args..., ...) volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args...) const volatile&& noexcept>
{
    using type = Ret(Args...) const volatile&&;
};

template<typename Ret, typename... Args>
struct remove_signature_nothrow<Ret(Args..., ...) const volatile&& noexcept>
{
    using type = Ret(Args..., ...) const volatile&&;
};

template<typename Signature>
using remove_signature_nothrow_t =
    typename remove_signature_nothrow<Signature>::type;

// remove all qualifiers from a signature

template<typename Signature>
struct remove_signature_qualifiers
{
    using type = remove_signature_variadic_t<
        remove_signature_const_t<remove_signature_volatile_t<
            remove_signature_lvalue_t<remove_signature_rvalue_t<
                remove_signature_nothrow_t<Signature>>>>>>;
};

template<typename Signature>
using remove_signature_qualifiers_t =
    typename remove_signature_qualifiers<Signature>::type;

namespace detail
{
template<typename Signature>
struct is_signature_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_helper<Ret(Args...)> : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature
    : public detail::is_signature_helper<remove_signature_variadic_t<
          remove_signature_const_t<remove_signature_volatile_t<
              remove_signature_lvalue_t<remove_signature_rvalue_t<
                  remove_signature_nothrow_t<Signature>>>>>>>
{};

template<typename Signature>
inline constexpr bool is_signature_v = is_signature<Signature>::value;

// variadic

namespace detail
{
template<typename T>
struct is_signature_variadic_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_variadic_helper<Ret(Args..., ...)> : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature_variadic
    : public std::conditional_t<
          detail::is_signature_variadic_helper<
              remove_signature_const_t<remove_signature_volatile_t<
                  remove_signature_lvalue_t<remove_signature_rvalue_t<
                      remove_signature_nothrow<Signature>>>>>>::value,
          std::true_type,
          std::false_type>
{};

template<typename Signature>
inline constexpr bool is_signature_variadic_v =
    is_signature_variadic<Signature>::value;

namespace detail
{
template<typename Signature>
struct is_signature_const_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_const_helper<Ret(Args...) const> : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature_const
    : public std::conditional_t<
          detail::is_signature_const_helper<
              remove_signature_variadic_t<remove_signature_volatile_t<
                  remove_signature_lvalue_t<remove_signature_rvalue_t<
                      remove_signature_nothrow_t<Signature>>>>>>::value,
          std::true_type,
          std::false_type>
{};

template<typename Signature>
inline constexpr bool is_signature_const_v =
    is_signature_const<Signature>::value;

// volatile functions

namespace detail
{
template<typename Signature>
struct is_signature_volatile_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_volatile_helper<Ret(Args...) volatile>
    : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature_volatile
    : public std::conditional_t<
          detail::is_signature_volatile_helper<
              remove_signature_variadic_t<remove_signature_const_t<
                  remove_signature_lvalue_t<remove_signature_rvalue_t<
                      remove_signature_nothrow_t<Signature>>>>>>::value,
          std::true_type,
          std::false_type>
{};

template<typename Signature>
inline constexpr bool is_signature_volatile_v =
    is_signature_volatile<Signature>::value;

// lvalue qualified

namespace detail
{
template<typename Signature>
struct is_signature_lvalue_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_lvalue_helper<Ret(Args...)&> : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature_lvalue
    : public std::conditional_t<
          detail::is_signature_lvalue_helper<
              remove_signature_variadic_t<remove_signature_const_t<
                  remove_signature_volatile_t<remove_signature_rvalue_t<
                      remove_signature_nothrow_t<Signature>>>>>>::value,
          std::true_type,
          std::false_type>
{};

template<typename Signature>
inline constexpr bool is_signature_lvalue_v =
    is_signature_lvalue<Signature>::value;

// rvalue qualified functions

namespace detail
{
template<typename Signature>
struct is_signature_rvalue_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_rvalue_helper<Ret(Args...) &&> : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature_rvalue
    : public std::conditional_t<
          detail::is_signature_rvalue_helper<
              remove_signature_variadic_t<remove_signature_const_t<
                  remove_signature_volatile_t<remove_signature_lvalue_t<
                      remove_signature_nothrow_t<Signature>>>>>>::value,
          std::true_type,
          std::false_type>
{};

template<typename Signature>
inline constexpr bool is_signature_rvalue_v =
    is_signature_rvalue<Signature>::value;

// nothrow functions

namespace detail
{
template<typename Signature>
struct is_signature_nothrow_helper : public std::false_type
{};

template<typename Ret, typename... Args>
struct is_signature_nothrow_helper<Ret(Args...) noexcept>
    : public std::true_type
{};
} // namespace detail

template<typename Signature>
struct is_signature_nothrow
    : public std::conditional_t<
          detail::is_signature_nothrow_helper<
              remove_signature_variadic_t<remove_signature_const_t<
                  remove_signature_volatile_t<remove_signature_lvalue_t<
                      remove_signature_rvalue_t<Signature>>>>>>::value,
          std::true_type,
          std::false_type>
{};

template<typename Signature>
inline constexpr bool is_signature_nothrow_v =
    is_signature_nothrow<Signature>::value;

// get return type

namespace detail
{
template<typename Sig>
struct signature_return_helper;

template<typename Ret, typename... Args>
struct signature_return_helper<Ret(Args...)>
{
    using type = Ret;
};
} // namespace detail

template<typename Signature>
struct signature_return : public detail::signature_return_helper<
                              sigma::remove_signature_qualifiers_t<Signature>>
{};

template<typename Signature>
using signature_return_t = typename signature_return<Signature>::type;

// get parameters as tuple

namespace detail
{
template<typename Signature>
struct signature_parameter_list_helper;

template<typename Ret, typename... Args>
struct signature_parameter_list_helper<Ret(Args...)>
{
    using type = sigma::parameter_list<Args...>;
};
} // namespace detail

template<typename Signature>
struct signature_parameter_list
    : public detail::signature_parameter_list_helper<
          remove_signature_qualifiers_t<Signature>>
{};

template<typename Signature>
using signature_parameter_list_t =
    typename signature_parameter_list<Signature>::type;

namespace detail
{
// the final merge from return and a single tuple
template<typename Signature>
struct make_signature_helper;

template<typename Ret, typename... Args>
struct make_signature_helper<Ret(sigma::parameter_list<Args...>)>
{
    using type = Ret(Args...);
};
} // namespace detail

template<typename Signature>
struct make_signature;

template<typename Ret, typename... Args>
struct make_signature<Ret(Args...)>
{
    using type = typename detail::make_signature_helper<Ret(
        typename sigma::merge_parameter_list<Args...>::type)>::type;
};

template<typename Signature>
using make_signature_t = typename make_signature<Signature>::type;

// get nth parameter

namespace detail
{
template<std::size_t N, typename Signature>
struct signature_nth_parameter_helper;

template<std::size_t N, typename Ret, typename... Args>
struct signature_nth_parameter_helper<N, Ret(Args...)>
{
    static_assert(N < sizeof...(Args), "N is out of bounds");
    using type = typename sigma::parameter_list<Args...>::template at<N>::type;
};
} // namespace detail

template<std::size_t N, typename Signature>
struct signature_nth_parameter
    : detail::signature_nth_parameter_helper<
          N,
          sigma::remove_signature_qualifiers_t<Signature>>
{
    static_assert(sigma::is_signature_v<Signature>,
                  "provided Signature is not a valid function signature");
};

template<std::size_t N, typename Signature>
using signature_nth_parameter_t =
    typename signature_nth_parameter<N, Signature>::type;

namespace detail
{
template<typename Signature,
         bool Variadic,
         bool Const,
         bool Volatile,
         bool Lvalue,
         bool Rvalue,
         bool Nothrow>
struct signature_traits_helper;

template<typename Ret,
         typename... Args,
         bool Variadic,
         bool Const,
         bool Volatile,
         bool Lvalue,
         bool Rvalue,
         bool Nothrow>
struct signature_traits_helper<Ret(Args...),
                               Variadic,
                               Const,
                               Volatile,
                               Lvalue,
                               Rvalue,
                               Nothrow>
{
    static constexpr bool is_variadic() noexcept
    {
        return Variadic;
    }

    static constexpr bool is_const() noexcept
    {
        return Const;
    }

    static constexpr bool is_volatile() noexcept
    {
        return Volatile;
    }

    static constexpr bool is_lvalue() noexcept
    {
        return Lvalue;
    }

    static constexpr bool is_rvalue() noexcept
    {
        return Rvalue;
    }

    static constexpr bool is_nothrow() noexcept
    {
        return Nothrow;
    }

    /**
     * a valid function signature cannot have const/volatile/lvalue/rvalue in
     * its signature.
     */
    static constexpr bool is_valid_function_signature() noexcept
    {
        return !is_const() && !is_volatile() && !is_lvalue() && !is_rvalue();
    }

    using parameter_list = typename sigma::parameter_list<Args...>;

    using unqualified_signature_type = Ret(Args...);

    // details
    using _variadic_signature_type = std::conditional_t<
        is_variadic(),
        sigma::add_signature_variadic_t<unqualified_signature_type>,
        unqualified_signature_type>;
    using _const_signature_type = std::conditional_t<
        is_const(),
        sigma::add_signature_const_t<_variadic_signature_type>,
        _variadic_signature_type>;
    using _volatile_signature_type = std::conditional_t<
        is_volatile(),
        sigma::add_signature_volatile_t<_const_signature_type>,
        _const_signature_type>;
    using _lvalue_signature_type = std::conditional_t<
        is_lvalue(),
        sigma::add_signature_lvalue_t<_volatile_signature_type>,
        _volatile_signature_type>;
    using _rvalue_signature_type = std::conditional_t<
        is_rvalue(),
        sigma::add_signature_rvalue_t<_lvalue_signature_type>,
        _lvalue_signature_type>;
    using _nothrow_signature_type = std::conditional_t<
        is_nothrow(),
        sigma::add_signature_nothrow_t<_rvalue_signature_type>,
        _rvalue_signature_type>;

    using return_type = Ret;

    using signature_type = _nothrow_signature_type;
    using function_type  = signature_type;

    using function_ptr_type = std::add_pointer_t<function_type>;
    using function_ref_type = std::add_lvalue_reference_t<function_type>;

    template<typename T>
    using member_function_pointer_type = signature_type(T::*);
};

} // namespace detail

template<typename Signature>
struct signature_traits : public detail::signature_traits_helper<
                              sigma::remove_signature_qualifiers_t<Signature>,
                              sigma::is_signature_variadic_v<Signature>,
                              sigma::is_signature_const_v<Signature>,
                              sigma::is_signature_volatile_v<Signature>,
                              sigma::is_signature_lvalue_v<Signature>,
                              sigma::is_signature_rvalue_v<Signature>,
                              sigma::is_signature_nothrow_v<Signature>>
{
    static_assert(sigma::is_signature_v<Signature>,
                  "Provided signature is not valid");
};

} // namespace sigma

#endif