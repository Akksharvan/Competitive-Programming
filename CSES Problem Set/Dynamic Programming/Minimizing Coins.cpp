#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<int> c(n);
	for (int &y : c) cin >> y;

	vector<int> dp(x + 1);
	fill(begin(dp), end(dp), -1); dp[0] = 0;

	for (int i = 0; i <= x; i++) {
		if (dp[i] == -1) continue;

		for (int &y : c) {
			if (i + y > x) continue;
			if (dp[i + y] < 0) dp[i + y] = dp[i] + 1;
			else if (dp[i + y] > dp[i] + 1) dp[i + y] = dp[i] + 1;
		}
	}

	cout << dp[x] << "\n";
	return 0;
}