#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int tortilla() {
	int n, m;
	vector<vector<int> > dp, a;

    cin >> n >> m;

    a.assign(n + 1, vector<int>(m + 1, 0));
    dp.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		cin >> a[i][j];
    	}
    }

    dp[1][1] = a[1][1];
    for (int j = 2; j <= m; ++j) {
		dp[1][j] = dp[1][j - 1] + a[1][j];
	}
    for (int i = 2; i <= n; ++i) {
		dp[i][1] = dp[i - 1][1] + a[i][1];
	}

    for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			int r = min(dp[i - 1][j], dp[i][j - 1]);
			r = min(r, dp[i - 1][j - 1]);

			dp[i][j] = a[i][j] + r;
		}
	}

	cout << dp[n][m];

    return 0;
}
