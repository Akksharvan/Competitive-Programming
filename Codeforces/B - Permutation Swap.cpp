#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x : a) cin >> x;
	vector<int> b; for (int i = 0; i < n; i++) b.push_back(a[i] - 1 - i);

	int res = b[0];
	for (int &x : b) res = gcd(res, x);

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