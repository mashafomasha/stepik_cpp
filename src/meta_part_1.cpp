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

template<typename T>
struct Length
{
	static int const value = 1 + Length<typename T::Tail>::value;
};

template<>
struct Length<IntList<>>
{
	static int const value = 0;
};

template<int H, typename IL>
struct IntCons;

template<int H, int ... T>
struct IntCons<H, IntList<T...>>
{
	using type = IntList<H, T...>;
};

template<typename T, typename P>
struct Concat;

template<int ... T, int ... P>
struct Concat<IntList<T...>, IntList<P...>>
{
	using type = IntList<T..., P...>;
};

template<int N>
struct Generate
{
	using type = typename Concat<typename Generate<N - 1>::type, IntList<N - 1>>::type;
};

template<>
struct Generate<0>
{
	using type = IntList<>;
};

template<typename T>
void check()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template <int N>
using sequence_t = typename Generate<N>::type;

template <typename F, typename TUP, int ... INDICES>
auto apply_(const F & f, const TUP & tup, IntList<INDICES...>) -> decltype(f(std::get<INDICES>(tup) ...))
{
    return f(std::get<INDICES>(tup) ...);
}

template <typename F, typename ... Ts>
auto apply(const F & f, const std::tuple<Ts...> & tup) -> decltype(apply_(f, tup, sequence_t<sizeof...(Ts)>{}))
{
    return apply_(f, tup, sequence_t<sizeof...(Ts)>{});
}
