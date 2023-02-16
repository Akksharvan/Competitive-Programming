#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n; long long int res = LLONG_MAX;
	vector<long long int> a(n); for (long long int &x : a) cin >> x;

	for (int i = 1; i < (1 << n); i++) {
		long long int ret1 = 0;
		long long int ret2 = 0;

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) ret1 += a[j];
			else ret2 += a[j];
		}

		res = min(res, abs(ret1 - ret2));
	}

	cout << res << "\n";
	return 0;
}