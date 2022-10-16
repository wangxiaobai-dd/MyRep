/* 
 * Copyright (C) 2022 Meepo All Rights Reserved.
 * 
 * File Name     : TestFunctionTraits.cpp
 * Author        : Meepo
 * Creation Date : 2022-08-19
 * INFO          :
 *
 */


#include <cstdio>
#include <tuple>
#include <functional>
#include <iostream>
template <typename T>
struct function_traits;

/*
template <typename Ret, typename Arg, typename... Args>
struct function_traits<Ret(Arg, Args...)> {
public:
    enum { arity = sizeof...(Args) + 1 };
    typedef Ret function_type(Arg, Args...);
    typedef Ret return_type;
    using stl_function_type = std::function<function_type>;
    typedef Ret (*pointer)(Arg, Args...);

    //typedef std::tuple<Arg, Args...> tuple_type;
    typedef std::tuple<std::remove_const_t<std::remove_reference_t<Arg>>,
            std::remove_const_t<std::remove_reference_t<Args>>...>
            bare_tuple_type;
    using args_tuple_2nd =
            std::tuple<std::remove_const_t<std::remove_reference_t<Args>>...>;
};
 */

template <typename Ret, typename... Args>
struct function_traits<Ret(Args...)>
{
public:
    enum{ arity = sizeof...(Args) + 1 };

    typedef Ret function_type(Args...);

    typedef Ret return_type;
   // using stl_function_type = std::function<function_type>;

    typedef Ret (* pointer)(Args...);

    using args_tuple = std::tuple<typename std::decay_t<Args>...>;

    template <size_t I>
    struct arg
    {
        using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
    };
	using argType0 = typename arg<0>::type;
};


// 空参数
/*
template <typename Ret> struct function_traits<Ret()> {
public:
    enum { arity = 0 };
    typedef Ret function_type();
    typedef Ret return_type;
    using stl_function_type = std::function<function_type>;
    typedef Ret (*pointer)();

    //ypedef std::tuple<> tuple_type;
    typedef std::tuple<> bare_tuple_type;

    using args_tuple_2nd = std::tuple<>;
};
 */

// 函数指针
template <typename Ret, typename... Args>
struct function_traits<Ret (*)(Args...)> : function_traits<Ret(Args...)>{};

// std::function
template <typename Ret, typename... Args>
struct function_traits<std::function<Ret(Args...)>> : function_traits<Ret(Args...)>
{
};

// 成员函数
template <typename ReturnType, typename ClassType, typename... Args>
struct function_traits<ReturnType (ClassType::*)(Args...)> : function_traits<ReturnType(Args...)>
{
};

// 成员函数 const
template <typename ReturnType, typename ClassType, typename... Args>
struct function_traits<ReturnType (ClassType::*)(Args...) const> : function_traits<ReturnType(Args...)>
{
};

// 函数对象
template <typename Callable>
struct function_traits : function_traits<decltype(&Callable::operator())>{};

struct stDataBaseCmd
    {

    };

    struct stTestDataCmd : stDataBaseCmd
    {
        int userID = 0;
        int unionID = 0;
        int value = 0;
    };
void testData(const stDataBaseCmd* data, unsigned int size)
{
  
}
void testData2(){}

	template <typename Function, typename = std::enable_if_t< std::is_same_v<typename function_traits<Function>::argType0, const stDataBaseCmd*>  >>
void bindF(Function func)
{
}

int main()
{
     //std::cout << std::is_same<const stDataBaseCmd*, function_traits<decltype(testData)>::argType0>::value << std::endl;
	bindF(testData);
}
