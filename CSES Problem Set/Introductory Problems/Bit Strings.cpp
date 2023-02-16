#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const long long int MOD = 1e9 + 7;
	long long int n; cin >> n;

	long long int res = 1;
	while (n--) { res *= 2; if (res > MOD) res = res % MOD; }

	cout << res << "\n";
	return 0;
}