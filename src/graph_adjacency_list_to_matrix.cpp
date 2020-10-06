#include <iostream>
#include <vector>
#include <string>

using namespace std;

int graph_adjacency_list_to_matrix() {
	int n;
	vector<vector<int> > l;
	vector<vector<int> > mtr;

	cin >> n;

	l.resize(n + 1, vector<int>());
	mtr.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i) {
		int d, e;
		cin >> d;

		for (int j = 0; j < d; ++j) {
			cin >> e;
			l[i].push_back(e);
		}
	}

	for (int i = 1; i <= n; ++i) {
		vector<int> v = l[i];
		for (int j = 0; j < v.size(); ++ j) {
			mtr[i][v[j]] = 1;
			mtr[v[j]][i] = 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << mtr[i][j];
		}
		cout << endl;
	}

    return 0;
}
