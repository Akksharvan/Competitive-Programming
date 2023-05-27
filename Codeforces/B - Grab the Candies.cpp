#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x : a) cin >> x;

	int res = 0, ret = 0;
	for (int &x : a) {res += x; if (!(x % 2)) { ret += x; } }

	if (ret > (res - ret)) cout << "YES" << "\n";
	else cout << "NO" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}