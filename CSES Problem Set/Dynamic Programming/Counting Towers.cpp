#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	array<long long, (int) 1e6 + 1> d;
	array<long long, (int) 1e6 + 1> p;
	
	d[0]= 1; p[0] = 1;
	for (int i = 1; i < (int) 1e6 + 1; i++) {
		d[i] = 4 * d[i - 1] + p[i - 1]; d[i] %= MOD;
		p[i] = 2 * p[i - 1] + d[i - 1]; p[i] %= MOD;
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << ((d[n - 1] + p[n - 1]) % MOD) << "\n";
	}

	return 0;
}