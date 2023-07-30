#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
	long long n; cin >> n;
	vector<long long> a(n); for (long long &x : a) cin >> x;
	vector<long long> b(n); for (long long &x : b) cin >> x;

	sort(rbegin(a), rend(a));
	sort(rbegin(b), rend(b));

	long long res = 1, ret = 0;
	for (long long i = 0; i < n; i++) {
		while (ret < n && a[ret] > b[i]) ret++;
		res *= (ret - i); res %= MOD;
	}

	cout << (res % MOD) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}