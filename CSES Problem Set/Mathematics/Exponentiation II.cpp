#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long int foo (long long int a, long long int b, long long int c) {
	if (!b) return 1;
	long long res = foo(a, b / 2, c) % c;
	if (b % 2) return res % c * res % c * a % c;
	else return res * res % c;
}

void solve() {
	long long int a, b, c; cin >> a >> b >> c;
	cout << foo(a, foo(b, c, MOD - 1), MOD) << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}