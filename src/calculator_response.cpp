#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculator_response() {

	int n;
	vector<int> dp;
	vector<int> a;

    cin >> n;

    dp.resize(n + 1);

    for(int i = 2; i <= n; ++i) {
    	int t = dp[i - 1];
    	if (i % 2 == 0)
    		t = min(t, dp[i / 2]);
    	if (i % 3 == 0)
    		t = min(t, dp[i / 3]);

    	dp[i] = t + 1;
    }

    int i = n;
    while (i >= 1) {
    	a.push_back(i);

    	if (i % 2 == 0 && dp[i / 2] + 1 == dp[i])
    		i = i / 2;
    	else if (i % 3 == 0 && dp[i / 3] + 1 == dp[i])
    	    i = i / 3;
    	else
    		i = i - 1;
    }

    cout << dp[n] << endl;
    for (int i = a.size() - 1; i >= 0; --i) {
    	cout << a[i] << " ";
    }

    return 0;
}
