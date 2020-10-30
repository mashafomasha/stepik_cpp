#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <string>

using namespace std;

int m, n;

queue<pair<int, int> > q;

vector<vector<int> > visited;
vector<vector<char> > mp;
vector<vector<char> > res;

int main() {
	cin >> n >> m;

	string tmp;
	getline(cin, tmp);

	mp.assign(2 * n + 1, vector<char>(2 * m + 1));
	res.assign(2 * n + 1, vector<char>(2 * m + 1));
	visited.assign(2 * n + 1, vector<int>(2 * m + 1, 0));

	for (int i = 0; i < 2 * n + 1; ++i) {
		string str;
		getline(cin, str);

		for (int j = 0; j < str.size(); ++j) {
			char ch = str[j];
			mp[i][j] = ch;
			res[i][j] = ch;

			if (ch == 'S') {
				q.push({i, j});
			}
			if (ch == 'D') {
				res[i][j] = ' ';
			}
		}
	}

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		int curr_i = curr.first;
		int curr_j = curr.second;

		visited[curr_i][curr_j] = 1;

		// BOTTOM WALL => CAN GO TO TOP
		if (mp[curr_i + 1][curr_j] == '-') {
			// GO TOP
			for (int i = curr_i; i > 0; i -= 2) {
				if (mp[i][curr_j] == 'D') {
					res[i][curr_j] = 'D';
				}
				if (
					mp[i][curr_j - 1] == '|'
					|| mp[i][curr_j + 1] == '|'
					|| mp[i - 1][curr_j] == '-'
					|| mp[i + 1][curr_j] == '-'
				) {
					if (visited[i][curr_j] == 0) {
						q.push({ i, curr_j });
						visited[i][curr_j] = 1;
					}
				}
				if (mp[i - 1][curr_j] == '-') {
					break;
				}
			}
		}

		// TOP WALL => CAN GO TO BOTTOM
		if (mp[curr_i - 1][curr_j] == '-') {
			// GO BOTTOM
			for (int i = curr_i; i < 2 * n + 1; i += 2) {
				if (mp[i][curr_j] == 'D') {
					res[i][curr_j] = 'D';
				}
				if (
					mp[i][curr_j - 1] == '|'
					|| mp[i][curr_j + 1] == '|'
					|| mp[i - 1][curr_j] == '-'
					|| mp[i + 1][curr_j] == '-'
				) {
					if (visited[i][curr_j] == 0) {
						q.push({ i, curr_j });
						visited[i][curr_j] = 1;
					}
				}
				if (mp[i + 1][curr_j] == '-') {
					break;
				}
			}
		}

		// RIGHT WALL => CAN GO TO LEFT
		if (mp[curr_i][curr_j + 1] == '|') {
			// GO LEFT
			for (int j = curr_j; j > 0; j -= 2) {
				if (mp[curr_i][j] == 'D') {
					res[curr_i][j] = 'D';
				}
				if (
					mp[curr_i][j - 1] == '|'
					|| mp[curr_i][j + 1] == '|'
					|| mp[curr_i - 1][j] == '-'
					|| mp[curr_i + 1][j] == '-'
				) {
					if (visited[curr_i][j] == 0) {
						q.push({ curr_i, j });
						visited[curr_i][j] = 1;
					}
				}
				if (mp[curr_i][j - 1] == '|') {
					break;
				}
			}
		}

		// LEFT WALL => CAN GO TO RIGHT
		if (mp[curr_i][curr_j - 1] == '|') {
			// GO RIGHT
			for (int j = curr_j; j < 2 * m + 1; j += 2) {
				if (mp[curr_i][j] == 'D') {
					res[curr_i][j] = 'D';
				}
				if (
					mp[curr_i][j - 1] == '|'
					|| mp[curr_i][j + 1] == '|'
					|| mp[curr_i - 1][j] == '-'
					|| mp[curr_i + 1][j] == '-'
				) {
					if (visited[curr_i][j] == 0) {
						q.push({ curr_i, j });
						visited[curr_i][j] = 1;
					}
				}
				if (mp[curr_i][j + 1] == '|') {
					break;
				}
			}
		}
	}

	for (auto r: res) {
		for (auto c: r) {
			cout << c;
		}
		cout << endl;
	}

    return 0;
}
