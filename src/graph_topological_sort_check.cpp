#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace graph_topological_sort_check {
	int n, m;
	vector<vector<int> > graph;
	vector<int> visited;
	vector<int> sort_to_check;
	vector<int> colors;
	int with_cycle = 0;

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

		colors[v] = 2;
	}

	bool check(int v) {
		visited[v] = 1;

		for (auto ch: graph[v]) {
			if (visited[ch] == 0) {
				return false;
			}
		}

		return true;
	}

	int main() {
		cin >> n >> m;

		visited.resize(n, 0);
		colors.resize(n, 0);
		graph.resize(n, vector<int>());
		sort_to_check.resize(n);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;

			u -= 1;
			v -= 1;

			graph[u].push_back(v);
		}

		for (int i = 0; i < n; ++i) {
			int u;
			cin >> u;

			u -= 1;

			sort_to_check[i] = u;
		}

		dfs(0);
		if (with_cycle == 1) {
			cout << "NO";
			return 0;
		}

		for (int i = sort_to_check.size() - 1; i >= 0; --i) {
			bool res = check(sort_to_check[i]);
			if (!res) {
				cout << "NO";
				return 0;
			}
		}

		cout << "YES";

		return 0;
	}
}
