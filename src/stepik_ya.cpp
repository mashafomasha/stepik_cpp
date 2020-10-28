#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <string>

using namespace std;

int m, n;
pair<int, int> s;
vector<pair<int, int> > d;
vector<vector<int> > w;
queue<pair<int, int> > q;
set<pair<int, int> > visited;
vector<vector<char> > mp;

int main() {
	cin >> n >> m;

	string tmp;
	getline(cin, tmp);

	w.assign(2 * n + 1, vector<int>(2 * m + 1, 0));
	mp.assign(2 * n + 1, vector<char>(2 * m + 1));

	for (int i = 0; i < 2 * n + 1; ++i) {
		string str;
		getline(cin, str);

		for (int j = 0; j < str.size(); ++j) {
			char ch = str[j];

			if (ch == 'S') {
				s = {i, j};
			}
			if (ch == 'D') {
				d.push_back({ i, j });
			}
			if (ch == '-' || ch == '|') {
				w[i][j] = 1;
			}

			mp[i][j] = ch;
		}
	}

	for (auto c: d) {
		while(!q.empty()) {
			q.pop();
		}
		visited.clear();

		q.push(c);
		int in_the_stock = 0;

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();

			visited.insert(curr);

			int curr_i = curr.first;
			int curr_j = curr.second;

			if (curr_i == s.first && curr_j == s.second) {
				in_the_stock = 1;
				break;
			}

			// to left
			for (int j = curr_j; j > 0; --j) {
				if (w[curr_i][j - 1] == 1) {
					if (visited.find({ curr_i, j }) == visited.end()) {
						q.push({ curr_i, j });
						visited.insert({ curr_i, j });
					}
					break;
				}
			}
			// to right
			for (int j = curr_j; j < 2 * m; ++j) {
				if (w[curr_i][j + 1] == 1) {
					if (visited.find({ curr_i, j }) == visited.end()) {
						q.push({ curr_i, j });
						visited.insert({ curr_i, j });
					}
					break;
				}
			}
			// to top
			for (int i = curr_i; i > 0; --i) {
				if (w[i - 1][curr_j] == 1) {
					if (visited.find({ i, curr_j }) == visited.end()) {
						q.push({ i, curr_j });
						visited.insert({ i, curr_j });
					}
					break;
				}
			}
			// to bottom
			for (int i = curr_i; i < 2 * n; ++i) {
				if (w[i + 1][curr_j] == 1) {
					if (visited.find({ i, curr_j }) == visited.end()) {
						q.push({ i, curr_j });
						visited.insert({ i, curr_j });
					}
					break;
				}
			}
		}

		if (!in_the_stock) {
			mp[c.first][c.second] = ' ';
		}
	}

	for (auto r: mp) {
		for (auto c: r) {
			cout << c;
		}
		cout << endl;
	}

    return 0;
}
