#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; cin >> n >> q;
	vector<int> a(n); for (int &x : a) cin >> x;
	
	vector<int> dp(n + 1);
	for (int i = 2; i < n; i++) {
		if (a[i - 2] >= a[i - 1] && a[i - 1] >= a[i]) dp[i + 1] = dp[i] + 1;
		else dp[i + 1] = dp[i];
	}

	while (q--) {
		int l, r; cin >> l >> r;
		if (r - l + 1 <= 2) cout << (r - l + 1) << "\n";
		else cout << ((r - l + 1) - (dp[r] - dp[l + 1])) << "\n";
	}

	return 0;
}