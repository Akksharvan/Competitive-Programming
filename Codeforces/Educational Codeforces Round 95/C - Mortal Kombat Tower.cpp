#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x : a) cin >> x;

	vector<vector<int>> dp(2, vector<int> (n + 1, (int) 1e9));
	dp[1][0] = 0;

	for (int j = 0; j < n; j++) {
		dp[0][j + 1] = min(dp[0][j + 1], dp[1][j] + a[j]);
		dp[1][j + 1] = min(dp[1][j + 1], dp[0][j]);

		if (j + 2 <= n) {
			dp[0][j + 2] = min(dp[0][j + 2], dp[1][j] + a[j] + a[j + 1]);
			dp[1][j + 2] = min(dp[1][j + 2], dp[0][j]);
		}
	}

	cout << min(dp[0][n], dp[1][n]) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}