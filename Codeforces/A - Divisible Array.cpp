#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n; vector<int> a(n); a[0] = (((n * (n + 1)) / 2)) % n + 1;
	for (int i = 2; i <= n; i++) a[i - 1] = i;

	for (int &x : a) cout << x << " ";
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}