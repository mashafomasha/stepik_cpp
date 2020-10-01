#include <iostream>
#include <list>
#include <functional>

#include <future>
#include <vector>
#include <iterator>

/**
 * Реализовать map_reduce нужно с использование std::async.
 * Функция не должна изменять или копировать последовательность.
 * У потоков не должно быть разделяемых неконстантных данных (соответственно, не нужны примитивы синхронизации).
 */

template<typename It, typename UnaryFn, typename BinaryFn>
auto map_reduce(It b, It e, UnaryFn fn1, BinaryFn fn2) -> decltype(fn2(fn1(*b), fn1(*b))) {
	auto res = fn1(*b);

	while(++b != e) {
		res = fn2(res, fn1(*b));
	}

	return res;
}

template<typename It, typename UnaryFn, typename BinaryFn, typename N>
auto map_reduce(It b, It e, UnaryFn fn1, BinaryFn fn2, N num) -> decltype(fn2(fn1(*b), fn1(*b))) {
	using R = decltype(fn2(fn1(*b), fn1(*b)));
	std::vector<std::future<R>> v;

	int distance = std::distance(b, e);
	int num_e = distance / num;

	for (int i = 1; i <= num; i++) {
		auto p = b;
		std::advance(b, i == num ? std::distance(b, e) : num_e);

		v.push_back(std::async(std::launch::async, map_reduce<It, UnaryFn, BinaryFn>, p, b, fn1, fn2));
	}

	// reduce
	auto v_b = v.begin();
	auto v_e = v.end();

	R res = (*v_b).get();
	while(++v_b != v_e) {
		res = fn2(res, (*v_b).get());
	}

	return res;
}
