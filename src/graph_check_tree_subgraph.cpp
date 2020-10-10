#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_check_tree_subgraph {
	int n, m, q;
	vector<vector<int> > list, list_to_use;
	vector<pair<int, int> > edges, edges_to_use;
	vector<int> visited;

	void dfs(int v, int p, int & res) {
		if (res == 0)
			return;

		visited[v] = 1;

		for (int ch: list_to_use[v]) {
			if (visited[ch] != 1) {
				dfs(ch, v, res);
			}
		}

		int every_visited = 1;
		for (auto ch: list[v]) {
			if (visited[ch] == 0) {
				every_visited = 0;
				break;
			}
		}

		if (every_visited == 0) {
			res = 0;
		}
	}

	int graph_check_tree_subgraph() {
		cin >> n >> m;

		visited.resize(n, 0);
		list.resize(n, vector<int>());
		list_to_use.resize(n, vector<int>());

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			u -= 1;
			v -= 1;

			int first = min(u, v);
			int second = max(u, v);

			edges.push_back({first, second});

			list[u].push_back(v);
			list[v].push_back(u);
		}

		cin >> q;

		for (int i = 0; i < q; ++i) {
			int edge_idx;
			cin >> edge_idx;

			pair<int, int> edge_to_use = edges[edge_idx - 1];
			edges_to_use.push_back(edge_to_use);

			list_to_use[edge_to_use.first].push_back(edge_to_use.second);
			list_to_use[edge_to_use.second].push_back(edge_to_use.first);
		}

		if (q != (n - 1)) {
			cout << "NO";
			return 0;
		}

		for (int i = 0; i < n; ++i) {
			visited.assign(n, 0);

			int res = 1;
			int start = i;

			dfs(start, -1, res);

			for (int j = 0; j < n; ++j) {
				if (visited[j] != 1)
					dfs(j, -1, res);
			}

			auto it = find(visited.begin(), visited.end(), 0);
			if (res && it == visited.end()) {
				cout << "YES";
				return 0;
			}
		}

		cout << "NO";

		return 0;
	}
}
