#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_connectivity_components {

	int n, m, v;
	vector<vector<int> > list;
	vector<int> visited;
	vector<int> connected_comp_idx;

	void dfs(int vertex, int curr_connected_comp_idx) {
		visited[vertex] = 1;
		connected_comp_idx[vertex] = curr_connected_comp_idx;

		for (auto child: list[vertex]) {
			if (visited[child] != 1) {
				dfs(child, curr_connected_comp_idx);
			}
		}
	}

	int graph_connectivity_components() {
		cin >> n >> m;

		list.resize(n, vector<int>());
		visited.assign(n, 0);
		connected_comp_idx.assign(n, 0);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			list[u - 1].push_back(v - 1);
			list[v - 1].push_back(u - 1);
		}

		int i = 1;
		auto it = find(visited.begin(), visited.end(), 0);

		while (it != visited.end()) {
			int idx = distance(visited.begin(), it);

			dfs(idx, i);

			++i;

			it = find(visited.begin(), visited.end(), 0);
		}

		for (auto e: connected_comp_idx) {
			cout << e << " ";
		}

		return 0;
	}
}
