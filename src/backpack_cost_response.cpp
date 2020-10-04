#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

int backpack_cost_response() {

	int n, s;
	vector<int> w, c;
	vector<vector<int> > dp;
	vector<vector<tuple<int, int, int> > > p;
	vector<int> ans_c;

	int INF = -1000;


    cin >> s >> n;

    w.assign(n + 1, 0);
    c.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(s + 1, INF));
    p.assign(n + 1, vector<tuple<int, int, int> >(s + 1, make_tuple(-1, -1, -1)));

    for (int i = 1; i <= n; ++i) {
    	cin >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= s; ++j) { // volume of the backpack
    		if (w[i] <= j) {
    			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
    		} else {
    			dp[i][j] = dp[i - 1][j];
    		}
		}
    }

    int ans = 0;
    int j_max = 0;
    for (int j = 0; j <= s; ++j) {
		ans = max(ans, dp[n][j]);
		if (ans == dp[n][j])
			j_max = j;
	}

    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= s; ++j) {
    		if (w[i] <= j) {
    			if (dp[i][j] == dp[i - 1][j - w[i]] + c[i]) {
    				p[i][j] = make_tuple(i - 1, j - w[i], c[i]);
    			} else {
    				p[i][j] = make_tuple(i - 1, j, -1);
    			}
    		} else {
    			p[i][j] = make_tuple(i - 1, j, -1);
    		}
    	}
    }

//    for (int i = 1; i <= n; ++i) {
//    	for (int j = 0; j <= s; ++j) {
//    		cout << "(" << get<0>(p[i][j]) << "," << get<1>(p[i][j]) << "," << get<2>(p[i][j]) << ")" << " ";
//    	}
//    	cout << endl;
//    }

    int i = n;
    int j = j_max;
    while (i >= 0 && j >= 0) {
    	auto prnt = p[i][j];

    	i = get<0>(prnt);
    	j = get<1>(prnt);
    	int c_curr = get<2>(prnt);

    	if (c_curr != -1)
    		ans_c.push_back(i);
    }

    cout << ans << " " << ans_c.size() << endl;

    for (int i = ans_c.size() - 1; i >= 0; --i) {
    	cout << ans_c[i] + 1 << " ";
    }

    return 0;
}
