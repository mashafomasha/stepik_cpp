#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int queen_response() {
	int n, m;
	vector<vector<long long> > dp, a, m_i, m_j, m_d;
	vector<vector<pair<int, int> > >p, mp_i, mp_j, mp_d;
	vector<pair<int, int> > ans;

    cin >> n >> m;

    a.assign(n, vector<long long>(m, 0));
    dp.assign(n, vector<long long>(m, 0));

    m_i.assign(n, vector<long long>(m, -1));
    m_j.assign(n, vector<long long>(m, -1));
    m_d.assign(n, vector<long long>(m, -1));

    p.assign(n, vector<pair<int, int> >(m, {-1, -1}));

    mp_i.assign(n, vector<pair<int, int> >(m, {0, 0}));
    mp_j.assign(n, vector<pair<int, int> >(m, {0, 0}));
    mp_d.assign(n, vector<pair<int, int> >(m, {0, 0}));

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		cin >> a[i][j];
    	}
    }

    dp[0][0] = a[0][0];

    m_i[0][0] = dp[0][0];
    m_j[0][0] = dp[0][0];
    m_d[0][0] = dp[0][0];

    for (int j = 1; j < m; ++j) {
    	dp[0][j] = m_i[0][j - 1] + a[0][j];
    	m_i[0][j] = min(m_i[0][j - 1], dp[0][j]);

    	m_j[0][j] = dp[0][j];
    	m_d[0][j] = dp[0][j];

    	p[0][j] = mp_i[0][j - 1];
    	if (m_i[0][j] < m_i[0][j - 1])
    		mp_i[0][j] = {0, j};
    	else
    		mp_i[0][j] = mp_i[0][j - 1];

    	mp_j[0][j] = {0, j};
    	mp_d[0][j] = {0, j};
    }
    for (int i = 1; i < n; ++i) {
    	dp[i][0] = m_j[i - 1][0] + a[i][0];
    	m_j[i][0] = min(m_j[i - 1][0], dp[i][0]);

    	m_i[i][0] = dp[i][0];
    	m_d[i][0] = dp[i][0];

    	p[i][0] = mp_j[i - 1][0];
    	if (m_j[i][0] < m_j[i - 1][0])
    		mp_j[i][0] = {i, 0};
    	else
    		mp_j[i][0] = mp_j[i - 1][0];

    	mp_i[i][0] = {i, 0};
    	mp_d[i][0] = {i, 0};
    }

    for (int i = 1; i < n; ++i) {
    	for (int j = 1; j < m; ++j) {
    		dp[i][j] = min(min(m_i[i][j - 1], m_j[i - 1][j]), m_d[i - 1][j - 1]) + a[i][j];

    		if (dp[i][j] == m_i[i][j - 1] + a[i][j]) {
    			pair<int, int> min_p = mp_i[i][j - 1];
    			int x = min_p.first;
    			int y = min_p.second;

    			if (dp[i][j - 1] != m_i[x][y])
    				p[i][j] = mp_i[i][j - 1];
    			else
    				p[i][j] = {i, j - 1};
    		}
    		else if (dp[i][j] == m_j[i - 1][j] + a[i][j]) {
    			pair<int, int> min_p = mp_j[i - 1][j];
    			int x = min_p.first;
    			int y = min_p.second;

    			if (dp[i - 1][j] != m_j[x][y])
    				p[i][j] = mp_j[i - 1][j];
    			else
    				p[i][j] = {i - 1, j};
    		}
    		else {
    			pair<int, int> min_p = mp_d[i - 1][j - 1];
    			int x = min_p.first;
    			int y = min_p.second;

    			if (dp[i - 1][j - 1] != m_d[i - 1][j - 1]) {
    				p[i][j] = mp_d[i - 1][j - 1];
    			} else {
    				p[i][j] = {i - 1, j - 1};
    			}
    		}

    		m_i[i][j] = min(m_i[i][j - 1], dp[i][j]);
    		m_j[i][j] = min(m_j[i - 1][j], dp[i][j]);
    		m_d[i][j] = min(m_d[i - 1][j - 1], dp[i][j]);

    		if (m_i[i][j] < m_i[i][j - 1])
    			mp_i[i][j] = {i, j};
    		else
    			mp_i[i][j] = mp_i[i][j - 1];

    		if (m_j[i][j] < m_j[i - 1][j])
    			mp_j[i][j] = {i, j};
    		else
    			mp_j[i][j] = mp_j[i - 1][j];

    		if (m_d[i][j] < m_d[i - 1][j - 1])
    			mp_d[i][j] = {i, j};
    		else
    			mp_d[i][j] = mp_d[i - 1][j - 1];
    	}
    }

	int i = n - 1;
	int j = m - 1;
	while (i >= 0 && j >= 0) {
		ans.push_back({ i, j });

		pair<int, int> prnt = p[i][j];
		i = prnt.first;
		j = prnt.second;
	}

	cout << dp[n - 1][m - 1] << " " << ans.size() << endl;
	for (int k = ans.size() - 1; k >= 0; --k) {
		cout << ans[k].first + 1 << " " << ans[k].second + 1 << endl;
	}

    return 0;
}
