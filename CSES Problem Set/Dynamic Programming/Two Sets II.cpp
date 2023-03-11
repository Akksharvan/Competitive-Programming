#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
array<array<int, 62625 + 1>, (int) 5e2> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; dp[0][0] = 1;
	if ((n * (n + 1) / 2) % 2) { cout << 0 << "\n"; return 0; }

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= (n * (n + 1) / 4); j++) {
			int ret = j - i; dp[i][j] = dp[i - 1][j];
			if (ret >= 0) { dp[i][j] += dp[i - 1][ret]; dp[i][j] %= MOD; }
		}
	}

	cout << dp[n - 1][n * (n + 1) / 4] << "\n";
	return 0;
}