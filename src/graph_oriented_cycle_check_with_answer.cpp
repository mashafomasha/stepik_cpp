#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_oriented_cycle_check_with_ans {
	int n, m, q;
	vector<vector<int> > graph;
	vector<int> colors;

	vector<int> ans;
	vector<int> parent;

	int with_cycle = 0;
	int cycle_end = -1;
	int cycle_start = -1;

	void dfs(int v) {
		colors[v] = 1;

		for (auto ch: graph[v]) {
			parent[ch] = v;

			if (colors[ch] == 1) {
				cycle_end = v;
				cycle_start = ch;
				with_cycle = 1;
			}
			if (colors[ch] == 0) {
				dfs(ch);
			}
		}

		colors[v] = 2;
	}

	int main() {
		cin >> n >> m;

		colors.resize(n, 0);
		graph.resize(n, vector<int>());
		parent.resize(n, -1);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			u -= 1;
			v -= 1;

			graph[u].push_back(v);
		}

		for (int i = 0; i < n; ++i) {
			if (colors[i] == 0)
				dfs(i);
		}

		if (with_cycle == 0) {
			cout << "NO";
		} else {
			cout << "YES" << endl;
			for (int i = cycle_end; i != cycle_start; i = parent[i]) {
				ans.push_back(i);
			}
			ans.push_back(cycle_start);

			cout << ans.size() << endl;
			for (int i = ans.size() - 1; i >= 0; --i) {
				cout << ans[i] + 1 << " ";
			}
		}

		return 0;
	}
}
