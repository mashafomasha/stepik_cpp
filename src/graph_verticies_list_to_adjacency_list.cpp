#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int graph_verticies_list_to_adjacency_list() {
	int n, m;
	vector<pair<int, int> > l_uv;
	vector<set<int> > l_sm;

	cin >> n >> m;

	l_sm.resize(n + 1, set<int>());

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		l_uv.push_back({u, v});
	}

	for (int i = 0; i < m; ++i) {
		auto p = l_uv[i];

		l_sm[p.first].insert(p.second);
		l_sm[p.second].insert(p.first);
	}

	for (int i = 1; i <= n; ++i) {
		cout << l_sm[i].size() << " ";

		for (auto e: l_sm[i]) {
			cout << e << " ";
		}
		cout << endl;
	}

    return 0;
}
