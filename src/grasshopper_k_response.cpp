#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int grasshopper_k_response() {
	int n, k;
	vector<long long> dp, a;
	vector<int>p;
	vector<int> ans;

	typedef pair<long long, int> Pair;

	struct Compare {
	  bool operator ()(const Pair& p1, const Pair& p2) const {
	    if (p1.first != p2.first) return p1.first < p2.first;
	    return p1.second < p2.second;
	  }
	};

	multiset<pair<long long, int>, Compare> dp_min;

    cin >> n >> k;

    a.assign(n, 0);
    dp.assign(n, 0);
    p.assign(n, -1);

    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    dp[0] = a[0];
    dp_min.insert({a[0], 0});

    for (int i = 1; i < k; ++i) {
    	auto it = dp_min.begin();
		auto dp_min_curr = *it;
		auto dp_min_curr_value = dp_min_curr.first;
		auto dp_min_curr_idx = dp_min_curr.second;

		if (dp_min_curr_value > 0) {
			dp_min_curr_value = 0;
			dp_min_curr_idx = -1;
		}

		dp[i] = dp_min_curr_value + a[i];
		p[i] = dp_min_curr_idx;

		dp_min.insert({dp[i], i});

//		for (auto e: dp_min)
//			cout << i << " " << e.first << " " << e.second << "; ";
//		cout << endl;
    }

    for (int i = k; i < n; ++i) {
    	auto it = dp_min.begin();
    	auto dp_min_curr = *it;
    	auto dp_min_curr_value = dp_min_curr.first;
    	auto dp_min_curr_idx = dp_min_curr.second;

    	dp[i] = dp_min_curr_value + a[i];
    	p[i] = dp_min_curr_idx;

    	auto it_to_remove = dp_min.equal_range({ dp[i - k], i - k });
    	dp_min.erase(it_to_remove.first);

    	dp_min.insert({dp[i], i});

//    	for (auto e: dp_min)
//    		cout << i << " " << e.first << " " << e.second << "; ";
//    	cout << endl;
    }

    int i = n - 1;
    while (i >= 0) {
    	ans.push_back(i);

    	int x = p[i];
    	i = x;
    }

    cout << dp[n - 1] << " " << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; --i) {
    	cout << ans[i] + 1 << " ";
    }

    return 0;
}
