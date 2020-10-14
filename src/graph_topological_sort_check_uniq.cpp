#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_topological_sort_check_uniq {
	int n, m;
	vector<vector<int> > graph;
	vector<int> graph_sort_variant;
	vector<int> visited;

	void dfs(int v) {
		visited[v] = 1;

		for (auto ch: graph[v]) {
			if (visited[ch] == 0) {
				dfs(ch);
			}
		}

		graph_sort_variant.push_back(v);
	}

	int main() {
		cin >> n >> m;

		visited.resize(n, 0);
		graph.resize(n, vector<int>());

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			u -= 1;
			v -= 1;

			graph[u].push_back(v);
		}

		for (int i = 0; i < n; ++i) {
			if (visited[i] == 0)
				dfs(i);
		}

		for (int i = graph_sort_variant.size() - 1; i > 0; --i) {
			auto ch = graph[graph_sort_variant[i]];
			auto it = find(ch.begin(), ch.end(), graph_sort_variant[i - 1]);
			if (it == ch.end()) {
				cout << "NO" << endl;
				return 0;
			}
		}

		cout << "YES" << endl;

		return 0;
	}
}
