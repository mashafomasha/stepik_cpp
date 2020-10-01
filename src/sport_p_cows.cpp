#include <iostream>

using namespace std;

int cnt(long a[10050], int n, long mid) {
    int c = 1;

    int prev = 0;
    for (int i = 1; i < n; i++) {
    	if (a[i] - a[prev] >= mid) {
    		c += 1;
    		prev = i;
    	}
    }

    return c;
}

int solution_cows() {
	int n, k;
	long a[10050];

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long l = 0;
    long r = 100000200;
    long mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;

        int c = cnt(a, n, mid);
        cout << mid << " " << c << endl;

        if (c < k)
            r = mid;
        else
            l = mid;
    }

    cout << l;

    return 0;
}
