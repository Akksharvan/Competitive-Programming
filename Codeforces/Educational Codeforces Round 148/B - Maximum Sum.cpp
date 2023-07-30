#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<long long> a(n); for (long long &i : a) cin >> i; sort(begin(a), end(a));
	vector<long long> dp(n + 1); for (int i = 0; i < n; i++) dp[i + 1] = dp[i] + a[i];

	long long res = 0;
	for (int i = 0; i <= k; i++) res = max(res, dp[n - (k - i)] - dp[2 * i]);

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