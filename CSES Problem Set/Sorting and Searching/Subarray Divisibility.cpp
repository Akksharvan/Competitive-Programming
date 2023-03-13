#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	long long int ret = 0; vector<long long int> dp(n);
	for (int i = 0; i < n; i++) { int x; cin >> x; ret += x; dp[(ret % n + n) % n]++; }

	long long int res = 0; dp[0] += 1;
	for (long long int &p : dp) res += p * (p - 1) / 2;

	cout << res << "\n";
	return 0;
}