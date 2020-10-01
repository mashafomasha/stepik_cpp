#include <iostream>
#include <tuple>

template<int ... T>
struct IntList;

template<int H, int ... T>
struct IntList<H, T...>
{
	static int const Head = H;
	using Tail = IntList<T...>;
};

template<>
struct IntList<>
{};

template<int H, typename IL>
struct IntCons;

template<int H, int ... T>
struct IntCons<H, IntList<T...>>
{
	using type = IntList<H, T...>;
};

template<typename F, typename S, template<int A, int B> class Fn>
struct Zip
{
	using type = typename IntCons<Fn<F::Head, S::Head>::value, typename Zip<typename F::Tail, typename S::Tail, Fn>::type>::type;
};

template<template<int A, int B> class Fn>
struct Zip<IntList<>, IntList<>, Fn>
{
	using type = IntList<>;
};

template<int a, int b>
struct Plus
{
	static int const value = a + b;
};

using L1 = IntList<1,2,3,4,5>;
using L2 = IntList<1,3,7,7,2>;

using L3 = Zip<L1, L2, Plus>::type;  // IntList<2, 5, 10, 11, 7>

template<typename T>
void check()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}
