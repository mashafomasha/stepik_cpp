#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long smallest(long long x, long long y, long long z)
{
  return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int tr() {
	int n, m;
	long long MAX = 1000 * 1000 * 1000 + 1;
	vector<vector<long long> > a, dp;
	vector<pair<int, int> > b;

	cin >> n >> m;

	a.assign(n + 1, vector<long long>(m + 1, 0));
	dp.assign(n + 1, vector<long long>(m + 1, MAX));
	dp[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = smallest(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}

	int i = n;
	int j = m;

	while (i >= 1 && j >= 1) {
		b.push_back({i, j});

		if (a[i][j] + dp[i][j - 1] == dp[i][j]) {
			j -= 1;
		} else if (a[i][j] + dp[i - 1][j] == dp[i][j]) {
			i -= 1;
		} else {
			i -= 1;
			j -= 1;
		}
	}

	cout << dp[n][m] << " " << b.size() << endl;

	for (int k = b.size() - 1; k >= 0; --k) {
		cout << b[k].first << " " << b[k].second << endl;
	}

    return 0;
}
