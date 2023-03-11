#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	array<long long int, (int) 1e7> dp{};
	
	for (int i = 1; i <= 6; i++) dp[i] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
	}

	cout << dp[n] << "\n";
	return 0;
}