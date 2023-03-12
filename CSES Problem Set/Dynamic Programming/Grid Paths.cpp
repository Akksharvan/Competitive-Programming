#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<vector<bool>> a(n + 1, vector<bool> (n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			a[i][j] = ((c == '.') ? (1) : (0));
		}
	}

	vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0)); dp[1][1] = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!a[i][j]) continue;
			dp[i][j] += dp[i - 1][j] % MOD + dp[i][j - 1] % MOD;
		}
	}

	cout << dp[n][n] % MOD << "\n";
	return 0;
}