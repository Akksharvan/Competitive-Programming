#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x; cin >> n >> x;
	vector<int> h(n); for (int &i : h) cin >> i;
	vector<int> s(n); for (int &i : s) cin >> i;

	array<array<int, (int) 1e5 + 1>, (int) 1e3 + 1> dp{};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			int ret = j - h[i - 1]; dp[i][j] = dp[i - 1][j];
			if (ret >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][ret] + s[i - 1]);
		}
	}

	cout << dp[n][x] << "\n";
	return 0;
}