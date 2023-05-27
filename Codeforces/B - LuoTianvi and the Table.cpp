#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m; int s = n * m;
	vector<int> a(s); for (int &x : a) cin >> x;

	sort(begin(a), end(a)); if (n > m) swap(n, m);
	int foo = (a[s - 2] - a[0]) * (n - 1);
	int bar = (a[s - 1] - a[1]) * (n - 1);
	int res = (a[s - 1] - a[0]) * (n * (m - 1));

	cout << (res + max(foo, bar)) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}