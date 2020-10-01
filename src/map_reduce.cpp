#include <iostream>
#include <list>

#include <functional>
#include <future>
#include <mutex>
#include <vector>
#include <iterator>

template<typename R, typename It, typename UnaryFn, typename BinaryFn>
void map_reduce(std::vector<R> & v_res, std::mutex & v_res_mutex, It b, It e, UnaryFn fn1, BinaryFn fn2) {
	const std::lock_guard<std::mutex> lock(v_res_mutex);

	R res = fn1(*b);

	while(++b != e) {
		res = fn2(res, fn1(*b));
	}

	v_res.push_back(res);
}

template<typename It, typename UnaryFn, typename BinaryFn, typename N>
auto map_reduce(It b, It e, UnaryFn fn1, BinaryFn fn2, N num) -> decltype(fn2(fn1(*b), fn1(*b))) {
	using R = decltype(fn2(fn1(*b), fn1(*b)));

	std::vector<R> v;
	std::mutex v_mutex;
	std::vector<std::thread> v_th;

	int distance = std::distance(b, e);
	int num_e = distance / num;

	for (int i = 1; i <= num; i++) {
		auto p = b;
		std::advance(b, i == num ? std::distance(b, e) : num_e);

		v_th.push_back(std::thread(map_reduce<R, It, UnaryFn, BinaryFn>, std::ref(v), std::ref(v_mutex), p, b, fn1, fn2));
	}

	for (auto & t: v_th) {
		t.join();
	}

	auto v_b = v.begin();
	auto v_e = v.end();

	R res = *v_b;
	while(++v_b != v_e) {
		res = fn2(res, *v_b);
	}

	return res;
}
