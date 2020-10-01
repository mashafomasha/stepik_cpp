#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int backpack_slisable_stone() {
	int n, s;
	vector<int> w;
	vector<vector<int> > dp;

    cin >> s >> n;

    w.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(s + 1, 0));

    for (int i = 1; i <= n; ++i) {
    	cin >> w[i];
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) { // stones to put into the backpack
    	for (int j = 0; j <= s; ++j) { // volume of the backpack
    		dp[i][j] = dp[i - 1][j] || dp[i - 1][max(j - w[i], 0)];
    	}
    }

    for (int j = s; j >= 0; --j) {
    	if (dp[n][j] == 1) {
    		cout << j << endl;
    		return 0;
    	}
    }

    return 0;
}
