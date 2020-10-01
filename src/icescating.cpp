#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int icescating() {
	int n;
	vector<vector<int> > dp, a;

	cin >> n;

    a.assign(n, vector<int>(n, 0));
    dp.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < i + 1; ++j) {
    		cin >> a[i][j];
    	}
    }

    dp[0][0] = a[0][0];
    for (int i = 1; i < n; ++i) {
    	dp[i][0] = dp[i - 1][0] + a[i][0];
    	dp[i][i] = dp[i - 1][i - 1] + a[i][i];
    }

    for (int i = 2; i < n; ++i) {
    	for (int j = 1; j < i; ++j) {
    		dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
    	}
    }

//    for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

    const auto mm = minmax_element(dp[n - 1].begin(), dp[n - 1].end());
    cout << *mm.second;

    return 0;
}
