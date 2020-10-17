#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

namespace graph_waves {
	int n, m, s;
	vector<vector<int> > graph;
	vector<int> visited;
	queue<int> q;

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
			graph[v].push_back(u);
		}

		cin >> s;
		s -= 1;
		q.push(s);

		while (!q.empty()) {
			int c = q.front();
			q.pop();

			visited[c] = 1;
			cout << c + 1 << " ";

			for (auto ch: graph[c]) {
				if (visited[ch] == 1) {
					continue;
				}

				visited[ch] = 1;
				q.push(ch);
			}
		}

		return 0;
	}
}
