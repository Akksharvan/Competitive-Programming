#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(m); for (int &x : a) cin >> x;
	vector<int> b(n); fill(begin(b), end(b), -1);
	
	set<int> c; int idx = n;
	for (int i = 0; i < m; i++) {
		if (c.find(a[i]) == end(c)) b[--idx] = i + 1;
		c.insert(a[i]); if (!idx) break;
	}

	for (int &x : b) cout << x << " ";
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}