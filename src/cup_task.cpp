#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <tuple>

using namespace std;

namespace cup_task {
	string str;
	map<tuple<int, int, int>, int > cache;

	int press_rec(int i, int prev_count, int prev_reg) {
		auto key = make_tuple(i, prev_count, prev_reg);
		auto it = cache.find(key);
		if (it != cache.end()) {
			return it->second;
		}

		int target_reg = str[i] == ' ' ? prev_reg : isupper(str[i]) ? 1 : 0;

		if (i >= str.size())
			return prev_count;

		int m;
		if (prev_reg != target_reg)
			m = min(
				press_rec(i + 1, prev_count + 2, prev_reg),
				press_rec(i + 1, prev_count + 3, prev_reg ? 0 : 1)
			);
		else
			m = press_rec(i + 1, prev_count + 1, prev_reg);

		cache[key] = m;
		return m;
	}

	int cup_task() {
		getline(cin, str);

		int res = press_rec(0, 0, 0);

		cout << res;

		return 0;
	}
}
