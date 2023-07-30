#include <bits/stdc++.h>
using namespace std;

int res;

void foo (int x, int y, int n, int r, vector<vector<int>> &v, vector<vector<bool>> &g) {
	if (x == (n - 1) && y == (n - 1)) { res = min(res, r); return; }
	if (x >= n || x < 0 || y >= n || y < 0 || r >= v[x][y] || g[x][y]) return;
	
	v[x][y] = r;
	foo(x + 1, y, n, r + 1, v, g);
	foo(x - 1, y, n, r + 1, v, g);
	foo(x, y + 1, n, r + 1, v, g);
	foo(x, y - 1, n, r + 1, v, g);

	return;
}

void solve() {
	int n; cin >> n; res = INT_MAX;
	vector<vector<bool>> g(n, (vector<bool> (n)));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			g[i][j] = (c == '.' ? 0 : 1);
		}
	}

	vector<vector<int>> v(n, (vector<int> (n, INT_MAX))); foo(0, 0, n, 0, v, g);

	cerr << res << "\n";
	cout << (res <= (2 * n - 2) ? "YES" : "NO") << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}