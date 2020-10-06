#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;

int graph_matrix_to_vericies_list() {
	int n;
	set<pair<int, int> > l;
	vector<vector<char> > mtr;

	cin >> n;

	mtr.resize(n + 1, vector<char>(n + 1, '0'));

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < n; ++j) {
			mtr[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mtr[i][j] == '1') {
				int first = min(i, j);
				int second = max(i, j);

				l.insert({first, second});
			}
		}
	}

	cout << l.size() << endl;
	for (auto e: l) {
		cout << e.first + 1 << " " << e.second + 1 << endl;
	}

    return 0;
}
