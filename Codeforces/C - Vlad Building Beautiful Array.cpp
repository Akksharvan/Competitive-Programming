#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &i : a) cin >> i;

	bool g = 0; int j = INT_MAX; int k = INT_MAX;
	for (int &i : a) { if (i % 2) { g = 1, j = min(i, j); } else { k = min(i, k); } }

	if (!g || (k - j > 0)) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}