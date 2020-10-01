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

template<typename T>
void check()
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// from
template<int m = 0, int kg = 0, int s = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
using Dimension = IntList<m, kg, s, A, K, mol, cd>;

template<int a, int b>
struct Plus
{
	static int const value = a + b;
};

template<int a, int b>
struct Minus
{
	static int const value = a - b;
};

template<typename T>
struct Quantity
{
	Quantity(): value_(0) {}
	explicit Quantity(double value): value_(value) {};

	double value() const {
		return value_;
	}

	using type = T;

private:
	double value_;
};

template<typename T>
Quantity<T> operator+(const Quantity<T> & f, const Quantity<T> & s) {
	double t = f.value() + s.value();
	return Quantity<T>(t);
};

template<typename T>
Quantity<T> operator-(const Quantity<T> & f, const Quantity<T> & s) {
	double t = f.value() - s.value();
	return Quantity<T>(t);
};

template<typename F>
Quantity<F> operator*(const double d, const Quantity<F> & s) {
	double t = d * s.value();
	return Quantity<F>(t);
}

template<typename F>
Quantity<F> operator*(const Quantity<F> & s, const double d) {
	double t = d * s.value();
	return Quantity<F>(t);
}

template<typename F, typename S>
Quantity<typename Zip<F, S, Plus>::type> operator*(const Quantity<F> & f, const Quantity<S> & s) {
	double t = f.value() * s.value();
	return Quantity<typename Zip<F, S, Plus>::type>(t);
}

template<typename F>
Quantity<typename Zip<Dimension<>, F, Minus>::type> operator/(const double d, const Quantity<F> & s) {
	double t = d / s.value();
	return Quantity<typename Zip<Dimension<>, F, Minus>::type>(t);
}

template<typename F>
Quantity<F> operator/(const Quantity<F> & s, const double d) {
	double t = s.value() / d;
	return Quantity<F>(t);
}

template<typename F, typename S>
Quantity<typename Zip<F, S, Minus>::type> operator/(const Quantity<F> & f, const Quantity<S> & s) {
	double t = f.value() / s.value();
	return Quantity<typename Zip<F, S, Minus>::type>(t);
}

// test

using NumberQ   = Quantity<Dimension<>>;           // число без размерности
using LengthQ   = Quantity<Dimension<1>>;          // метры
using MassQ     = Quantity<Dimension<0, 1>>;       // килограммы
using TimeQ     = Quantity<Dimension<0, 0, 1>>;    // секунды
using VelocityQ = Quantity<Dimension<1, 0, -1>>;   // метры в секунду
using AccelQ    = Quantity<Dimension<1, 0, -2>>;   // ускорение, метры в секунду в квадрате
using ForceQ    = Quantity<Dimension<1, 1, -2>>;   // сила в ньютонах
