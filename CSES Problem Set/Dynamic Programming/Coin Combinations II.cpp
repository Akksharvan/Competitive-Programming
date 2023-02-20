#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x; cin >> n >> x;
	vector<int> c(n); for (int &y : c) cin >> y;

	vector<long long int> dp(x + 1); dp[0] = 1;
	for (int i = 0; i < n; i++) for (int w = 0; w <= x; w++) if (w - c[i] >= 0) dp[w] += dp[w - c[i]] % MOD;

	cout << (dp[x] % MOD) << "\n";
	return 0;
}