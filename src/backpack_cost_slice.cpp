#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef pair<int, double> Pair;
struct Compare {
  bool operator ()(const Pair& p1, const Pair& p2) const {
	return p1.second < p2.second;
  }
};

int n, s;
vector<int> w, c;
multiset<pair<int, double>, Compare> stones;
vector<vector<int> > dp;

int INF = -1000;

int backpack_cost_slice() {
    cin >> s >> n;

    w.assign(n + 1, 0);
    c.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(s + 1, INF));

    for (int i = 1; i <= n; ++i) {
    	cin >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}

    for (int i = 1; i <= n; ++i) {
    	double c_i = c[i];
    	if (w[i] != 0)
    		c_i = (double) c[i] / w[i];

    	stones.insert({ i, c_i });
    }

    dp[0][0] = 0;

    int i = 1;
    for (auto it = stones.begin(); it != stones.end(); ++it) {
    	auto idx = (*it).first;
    	int w_i = w[idx];
    	int c_i = c[idx];

    	for (int j = 0; j <= s; ++j) { // volume of the backpack
			int c_curr = c_i;
			if (w_i != 0)
			{
				c_curr = (c_curr * min(w_i, j) + w_i - 1) / w_i;
			}

			dp[i][j] = max(
					dp[i - 1][j],
					dp[i - 1][max(j - w_i, 0)] + c_curr
			);
		}

    	i += 1;
    }

    int ans = 0;
    for (int j = 0; j <= s; ++j) {
		ans = max(ans, dp[n][j]);
	}

    cout << ans;

    return 0;
}
