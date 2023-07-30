#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; array<int, 51> d{};
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		if (l <= k && k <= r) for (int j = l; j <= r; j++) d[j]++;
	}

	for (int i = 1; i <= 50; i++) {
		if (i != k && d[i] >= d[k]) { cout << "NO" << "\n"; return; }
	}

	cout << "YES" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}