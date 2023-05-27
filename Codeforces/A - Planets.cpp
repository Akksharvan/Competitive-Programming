#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, c; cin >> n >> c;
	
	map<int, int> a;
	for (int i = 0; i < n; i++) { int x; cin >> x; a[x]++; }

	int res = 0;
	for (const pair<int, int> &p : a) {
		if (p.second > c) res += c;
		else res += p.second;
	}

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}