#pragma once

// All the following code is thanks to Brady, provided to community

namespace details {
    template <typename>
    struct resolve_func;

    template <typename R, typename... Args>
    struct resolve_func<R(Args...)> {
        template <typename T>
        struct memfn : std::type_identity<R (T::*)(Args...)> {};

        template <typename T>
        struct memfn<const T> : std::type_identity<R (T::*)(Args...) const> {};

        template <typename T>
        using memfn_t = typename memfn<T>::type;
    };

    template <typename R, typename T, typename... Args>
    struct resolve_func<R (T::*)(Args...)> {
        template <typename>
        using memfn_t = R (T::*)(Args...);
    };

    template <typename R, typename T, typename... Args>
    struct resolve_func<R (T::*)(Args...) const> {
        template <typename>
        using memfn_t = R (T::*)(Args...) const;
    };

    template <typename T>
    struct member_function_arg;

    template <typename T, typename Ret, typename Arg>
    struct member_function_arg<Ret (T::*)(Arg)> : std::type_identity<Arg> {};

    template <typename T, typename Ret, typename Arg>
    struct member_function_arg<Ret (T::*)(Arg) const> : std::type_identity<Arg> {};

    template <typename T>
    using member_function_arg_t = typename member_function_arg<T>::type;
}