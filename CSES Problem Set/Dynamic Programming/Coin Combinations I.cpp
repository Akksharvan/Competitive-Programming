#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x; cin >> n >> x;
	vector<int> c(n); for (int &y : c) cin >> y;

	vector<long long int> dp(x + 1); dp[0] = 1;
	for (int i = 1; i <= x; i++) for (int &y : c) if (i - y >= 0) dp[i] += dp[i - y] % MOD;

	cout << (dp[x] % MOD) << "\n";
	return 0;
}