#include <iostream>
#include <set>
#include <queue>
#include <map>

using namespace std;

namespace pq_horse {

int m, n, p, q;
int x_1, y_1, x_2, y_2;
queue<pair<int, int> > qu;
set<pair<int, int> > visited;
map<pair<int, int>, int > dist;

bool step(int x, int y, int d) {
	if (visited.find({ x, y }) != visited.end()) {
		return 0;
	}
	if (x <= 0 || y <= 0 || x > m || y > n) {
		return 0;
	}

	visited.insert({ x, y });
	qu.push({ x, y });
	dist.insert({ { x, y }, d });

	return 1;
}

int pq_horse() {
	cin >> m >> n >> p >> q >> x_1 >> y_1 >> x_2 >> y_2;

	qu.push({ x_1, y_1 });
	dist.insert({ { x_1, y_1 }, 0 });

	while(!qu.empty()) {
		auto v = qu.front();
		qu.pop();

		int x = v.first;
		int y = v.second;
		int d = dist[{ x, y }] + 1;

		visited.insert({ x, y });

		if (x == x_2 && y == y_2) {
			cout << d - 1;
			return 0;
		}

		// p q
		// to top left
		step(x - q, y - p, d);
		// to top right
		step(x - q, y + p, d);
		// to bottom left
		step(x + q, y - p, d);
		// to bottom right
		step(x + q, y + p, d);

		// q p
		// to top left
		step(x - p, y - q, d);
		// to top right
		step(x - p, y + q, d);
		// to bottom left
		step(x + p, y - q, d);
		// to bottom right
		step(x + p, y + q, d);
	}

	cout << -1;

    return 0;
}
}
