#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int grasshopper_response() {
	int n;
	vector<long long> c, a;
	vector<long long> dp;

	cin >> n;

	a.assign(n + 1, 0);
	dp.assign(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] + a[i];

		if (i - 3 >= 0)
			dp[i] = max(dp[i], dp[i - 3] + a[i]);
		if (i - 5 >= 0)
			dp[i] = max(dp[i], dp[i - 5] + a[i]);
	}

	int i = n;
	while (i > 0) {
		c.push_back(i);

		if (dp[i - 1] + a[i] == dp[i])
			i = i - 1;
		else if (dp[i - 3] + a[i] == dp[i])
			i = i - 3;
		else
			i = i - 5;
	}

	cout << dp[n] << " " << c.size() << endl;
	for (int i = c.size() - 1; i >= 0; --i) {
		cout << c[i] << " ";
	}

    return 0;
}
