#include <iostream>
#include <vector>
#include <string>

using namespace std;

int graph_verticies_list_to_matrix() {
	int n, m;
	vector<pair<int, int> > l_uv;
	vector<vector<int> > mtr;


	cin >> n >> m;

	mtr.resize(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		l_uv.push_back({u, v});
	}

	for (int i = 0; i < m; ++i) {
		auto p = l_uv[i];
		mtr[p.first][p.second] = 1;
		mtr[p.second][p.first] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << mtr[i][j];
		}
		cout << endl;
	}

    return 0;
}
