#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace dfs_with_steps {

	int n, m, v;
	vector<vector<int> > list;
	vector<int> visited;
	vector<int> route;
	vector<int> parent;

	void dfs_with_steps(int curr_v) {
		visited[curr_v] = 1;
		route.push_back(curr_v);

		bool every_child_visited = true;
		for (auto child_v: list[curr_v]) {
			if (visited[child_v] != 1) {
				parent[child_v] = curr_v;
				dfs_with_steps(child_v);
				every_child_visited = false;
				break;
			}
		}

		int p = parent[curr_v];
		if (every_child_visited && p != -1) {
			dfs_with_steps(p);
		}
	}

	int graph_dfs_with_steps() {
		cin >> n >> m;

		list.resize(n + 1, vector<int>());
		visited.assign(n + 1, 0);
		parent.assign(n + 1, -1);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			list[u].push_back(v);
			list[v].push_back(u);
		}

		cin >> v;
		dfs_with_steps(v);

		cout << route.size() << endl;
		for (auto e: route) {
			cout << e << " ";
		}

		return 0;
	}

}
