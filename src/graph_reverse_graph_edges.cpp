#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace reverse_graph_edges {
	int n, m;
	vector<vector<int> > list;
	vector<int> visited;
	set<pair<int, int> > rev;

	void dfs(int v, int p) {
		visited[v] = 1;

		for (int ch: list[v]) {
			if (ch == p)
				continue;

			if (visited[ch] != 1) {
				dfs(ch, v);
			} else {
				int first = min(v, ch);
				int second = max(v, ch);
				rev.insert({first, second});
			}
		}
	}

	int reverse_graph_edges() {
		cin >> n >> m;

		list.resize(n, vector<int>());
		visited.assign(n, 0);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			list[u - 1].push_back(v - 1);
			list[v - 1].push_back(u - 1);
		}

		for (int i = 0; i < n; ++i) {
			if (visited[i] != 1) {
				dfs(i, -1);
			}
		}

		cout << rev.size() << endl;

		return 0;
	}
}
