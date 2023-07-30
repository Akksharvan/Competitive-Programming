#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x : a) cin >> x;

	vector<int> p(n); p[0] = (a[0] == 2 ? 1 : 0);
	for (int i = 1; i < n; i++) p[i] = p[i - 1] + (a[i] == 2 ? 1 : 0);

	for (int i = 0; i < n - 1; i++) { if (p[i] == p[n - 1] - p[i]) { cout << i + 1 << "\n"; return; } }
	cout << -1 << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}