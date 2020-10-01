#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//long long bin_pow(unsigned long n, unsigned long p) {
//	long long res;
//
//    if (p == 0)
//        return 1;
//    if (p % 2 == 0) {
//    	long long tmp = bin_pow(n, p / 2);
//        res = (tmp * tmp) % MOD;
//    }
//    if (p % 2 == 1) {
//        res = (n * bin_pow(n, p - 1)) % MOD;
//    }
//
//    return res;
//}

int queen() {
	int n, m;
	vector<vector<long long> > dp, h, v, d;
	long long MOD = pow(10, 9) + 7;

	cin >> n >> m;

	dp.assign(n, vector<long long>(m, 1));
	h.assign(n, vector<long long>(m, 0));
	v.assign(n, vector<long long>(m, 0));
	d.assign(n, vector<long long>(m, 0));

	d[0][0] = 1;

	for (int i = 1; i < n; ++i) {
//		dp[i][0] = bin_pow(2, i - 1);

		d[i][0] = dp[i][0];
		h[i][0] = (h[i - 1][0] % MOD + dp[i - 1][0] % MOD) % MOD;
	}
	for (int j = 1; j < m; ++ j) {
//		dp[0][j] = bin_pow(2, j - 1);

		d[0][j] = dp[0][j];
		v[0][j] = (v[0][j - 1] % MOD + dp[0][j - 1] % MOD) % MOD;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			dp[i][j] = (v[i - 1][j] % MOD + h[i][j - 1] % MOD + d[i - 1][j - 1] % MOD) % MOD;

			v[i][j] = (v[i - 1][j] % MOD + dp[i][j] % MOD) % MOD;
			h[i][j] = (h[i][j - 1] % MOD + dp[i][j] % MOD) % MOD;
			d[i][j] = (d[i - 1][j - 1] % MOD + dp[i][j] % MOD) % MOD;
		}
	}

//	cout << "DP" << endl;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//
//	cout << "Horizontal" << endl;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << h[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//
//	cout << "Vertical" << endl;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << v[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	cout << endl;
//
//	cout << "Diagonal" << endl;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << d[i][j] << " ";
//		}
//		cout << endl;
//	}

	cout << dp[n - 1][m - 1];

    return 0;
}
