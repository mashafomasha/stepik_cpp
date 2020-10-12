#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_cycle_check {
	int n, m, q;
	vector<vector<int> > graph;
	vector<pair<int, int> > edges;
	vector<int> colors;

	void dfs(int v, int p) {
		colors[v] = 1;

		for (auto ch: graph[v]) {
			if (ch != p && colors[ch] == 1) {
				q = 1;
			}
			if (colors[ch] == 0) {
				dfs(ch, v);
			}
		}

		colors[v] = 2;
	}

	int main() {
		cin >> n >> m;

		colors.resize(n, 0);
		graph.resize(n, vector<int>());

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			u -= 1;
			v -= 1;

			int first = min(u, v);
			int second = max(u, v);

			edges.push_back({first, second});

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		q = 0;
		for (int i = 0; i < n; ++i) {
			if (colors[i] == 0)
				dfs(i, -1);
		}

		if (q)
			cout << "YES";
		else
			cout << "NO";

		return 0;
	}
}
