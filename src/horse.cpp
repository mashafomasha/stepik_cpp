#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int horse() {
	int n, m;
	vector<vector<long> > dp;
	long MOD = pow(10, 9) + 123;

	cin >> n >> m;

	dp.assign(n + 3, vector<long>(m + 3, 0));

	for (int k = 0; k <= n + m + 1; ++k) {
		for (int i = 2; i <= k; ++i) {
			int j = k - i + 2;

			if (i > (n + 1) || j > (m + 1))
				continue;

			if (i == 2 && j == 2)
				dp[i][j] = 1;
			else
				dp[i][j] = (
					dp[i - 1][j - 2] % MOD
				  + dp[i + 1][j - 2] % MOD
				  + dp[i - 2][j - 1] % MOD
				  + dp[i - 2][j + 1] % MOD
				) % MOD;
		}
	}

//	for (int i = 0; i <= n + 1; ++i) {
//		for (int j = 0; j <= m + 1; ++j) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

	cout << dp[n + 1][m + 1];

    return 0;
}
