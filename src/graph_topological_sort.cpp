#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_topological_sort {
	int n, m;
	vector<vector<int> > graph;
	vector<int> colors;

	vector<int> ans;

	int with_cycle = 0;
	int pos;

	void dfs(int v) {
		if (with_cycle == 1)
			return;

		colors[v] = 1;

		for (auto ch: graph[v]) {
			if (colors[ch] == 0) {
				dfs(ch);
			}

			if (colors[ch] == 1) {
				with_cycle = 1;
			}
		}

		ans[pos] = v;
		pos -= 1;
		colors[v] = 2;
	}

	int main() {
		cin >> n >> m;

		colors.resize(n, 0);
		graph.resize(n, vector<int>());
		ans.resize(n);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			u -= 1;
			v -= 1;

			graph[u].push_back(v);
		}

		pos = n - 1;
		for (int i = 0; i < n; ++i) {
			if (with_cycle == 0 && colors[i] == 0)
				dfs(i);
		}

		if (with_cycle == 1) {
			cout << "NO";
			return 0;
		}

		cout << "YES" << endl;

		for (auto e: ans) {
			cout << e + 1 << " ";
		}

		return 0;
	}
}
