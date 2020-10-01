#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int backpack_response() {
	int n, s;
	vector<int> w;
	vector<vector<int> > dp;
	vector<vector<pair<int, int> > > p;
	vector<int> ans;

    cin >> s >> n;

    w.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(s + 1, 0));
    p.assign(n + 1, vector<pair<int, int> >(s + 1, {-1, -1}));

    for (int i = 1; i <= n; ++i) {
    	cin >> w[i];
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) { // stones to put into the backpack
    	for (int j = 0; j <= s; ++j) { // volume of the backpack
    		if (w[i] <= j) {
    			dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i]];

    			if (dp[i][j] == dp[i - 1][j])
    				p[i][j] = {i - 1, j};
    			else
    				p[i][j] = {i - 1, j - w[i]};
    		}
    		else {
    			dp[i][j] = dp[i - 1][j];
    			p[i][j] = {i - 1, j};
    		}
    	}
    }

//    for (int i = 1; i <= n; ++i) {
//    	for (int j = 0; j <= s; ++j) {
//    		cout << p[i][j].first << " " << p[i][j].second << "; ";
//    	}
//    	cout << endl;
//    }

    for (int j = s; j >= 0; --j) {
    	if (dp[n][j] == 1) {
    		int a = n;
    		int b = j;

    		while (a > 0 && b > 0) {
    			auto t = p[a][b];
    			int idx = b - t.second > 0 ? a : -1;
    			if (idx != -1)
    				ans.push_back(idx);

    			a = t.first;
    			b = t.second;

//    			cout << a << " " << b << endl;
    		}

    		cout << j << " " << ans.size() << endl;
    		for (int k = ans.size() - 1; k >= 0; --k)
    			cout << ans[k] << " ";

    		break;
    	}
    }



    return 0;
}
