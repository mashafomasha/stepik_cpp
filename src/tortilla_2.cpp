#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tortilla_2() {
	int n, m;
	vector<vector<long> > dp, a;
	long MOD = pow(10, 9) + 9;

	cin >> n >> m;

    a.assign(n + 1, vector<long>(m + 1, 1));
    dp.assign(n + 1, vector<long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		cin >> a[i][j];
    	}
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		if (a[i][j] == 1)
    			dp[i][j] = 0;
    		else
    			dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
    	}
    }

//    for (int i = 0; i <= n; ++i) {
//		for (int j = 0; j <= m; ++j) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

    cout << dp[n][m];

    return 0;
}
