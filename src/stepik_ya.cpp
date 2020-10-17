#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, s;
vector<vector<int> > graph;
queue<int> q;
vector<int> dist;

int main() {
	cin >> n >> m;

	dist.resize(n, -1);
	graph.resize(n, vector<int>());

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		u -= 1;
		v -= 1;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	s = 0;

	for (int i = 0; i < n; ++i) {
		int start = i;

		dist.assign(n, -1);
		q.push(start);

		dist[start] = 0;

		while (!q.empty()) {
			int c = q.front();
			q.pop();

			if (c > start) {
				s += dist[c];

			}

			for (auto ch: graph[c]) {
				if (dist[ch] == -1) {
					dist[ch] = dist[c] + 1;
					q.push(ch);
				}
			}
		}
	}

	cout << s;

    return 0;
}
