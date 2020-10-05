#include <iostream>
#include <vector>
#include <string>

using namespace std;

int graph_matrix_to_list() {
	int n;
	vector<vector<int> > m;
	vector<vector<int> > l;

	cin >> n;

	m.assign(n, vector<int>(n, 0));
	l.assign(n, vector<int>());

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		for (int j = 0; j < n; ++j) {
			m[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] == '1')
				l[i].push_back(j + 1);
		}
	}

	for (auto row: l) {
		cout << row.size() << " ";
		for (auto elem:  row)
			cout << elem << " ";
		cout << endl;
	}

	return 0;
}
