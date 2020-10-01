#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int knight_response() {
	int n, m;
	vector<vector<long long> > dp, a;
	vector<vector<int> >p_x, p_y;

	long long MAX = pow(10, 9) * 1000 * 1000 + 1;

    cin >> n >> m;

    dp.assign(n, vector<long long>(m, MAX));
    a.assign(n, vector<long long>(m, MAX));
    p_x.assign(n, vector<int>(m, -1));
    p_y.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		cin >> a[i][j];
    	}
    }

    dp[0][0] = a[0][0];

    int d = n + m - 1;
    for (int k = 2; k <= d; ++k) {
    	for (int i = 0; i <= k; ++i) {
    		int j = k - i;

    		if (j >= m || i >= n)
    			continue;

    		long long t = MAX;

    		if (i + 1 < n && j - 2 >= 0) {
    			t = min(t, dp[i + 1][j - 2]);
    		}
    		if (i - 1 >= 0 && j - 2 >= 0) {
    			t = min(t, dp[i - 1][j - 2]);
    		}
    		if (i - 2 >= 0 && j - 1 >= 0) {
    			t = min(t, dp[i - 2][j - 1]);
    		}
    		if (i - 2 >= 0 && j + 1 < m) {
    			t = min(t, dp[i - 2][j + 1]);
    		}

			if (t == MAX) {
				dp[i][j] = t;
			}
			else {
				dp[i][j] = t + a[i][j];

			}

			if (dp[i][j] != MAX) {
				if (i + 1 < n && j - 2 >= 0 && dp[i][j] == dp[i + 1][j - 2] + a[i][j]) {
					p_x[i][j] = i + 1;
					p_y[i][j] = j - 2;
				} else if (i - 1 >= 0 && j - 2 >= 0 && dp[i][j] == dp[i - 1][j - 2] + a[i][j]) {
					p_x[i][j] = i - 1;
					p_y[i][j] = j - 2;
				} else if (i - 2 >= 0 && j - 1 >= 0 && dp[i][j] == dp[i - 2][j - 1] + a[i][j]) {
					p_x[i][j] = i - 2;
					p_y[i][j] = j - 1;
				} else if (i - 2 >= 0 && j + 1 < m && dp[i][j] == dp[i - 2][j + 1] + a[i][j]) {
					p_x[i][j] = i - 2;
					p_y[i][j] = j + 1;
				}
			}
    	}
    }

    if (dp[n - 1][m - 1] == MAX) {
    	cout << "NO";
    	return 0;
    }

    vector<pair<int, int> > r;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0) {
    	r.push_back({ i, j });

    	int x = i;
    	int y = j;

    	i = p_x[x][y];
    	j = p_y[x][y];
    }

    cout << "YES" << endl;
    cout << dp[n - 1][m - 1] << " " << r.size() << endl;
    for (int i = r.size() - 1; i >=0; --i) {
    	cout << r[i].first + 1 << " " << r[i].second + 1 << endl;
    }

    return 0;
}
