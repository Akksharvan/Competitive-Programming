#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a) cin >> x;

	int neg = 0;
	for (int &x : a) if (x < 0) neg++;

	long long int res = 0;
	for (int &x : a) { x = abs(x); res += x; }

	int ret = INT_MAX;
	for (int &x : a) ret = min(ret, x);

	if (neg % 2) res -= (2 * ret);
	cout << res << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}