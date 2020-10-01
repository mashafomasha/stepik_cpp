#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int battle() {
	int n, m;
	vector<vector<int> > dp, h;


	cin >> m >> n;

    h.assign(n + 1, vector<int>(m + 1, 0));
    dp.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		cin >> h[i][j];
    	}
    }

    dp[0][0] = 0;
    for (int j = 1; j < m; ++j) {
    	dp[0][j] = dp[0][j - 1] + abs(h[0][j] - h[0][j - 1]);
    }

    for (int i = 1; i < n; ++i) {
    	dp[i][0] = dp[i - 1][0] + abs(h[i][0] - h[i - 1][0]);
    }

    for (int i = 1; i < n; ++i) {
    	for (int j = 1; j < m; ++j) {
    		dp[i][j] = min(
				dp[i - 1][j] + abs(h[i][j] - h[i - 1][j]),
				dp[i][j - 1] + abs(h[i][j] - h[i][j - 1])
			);
    	}
    }

//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;

    cout << dp[n - 1][m - 1];

    return 0;
}
