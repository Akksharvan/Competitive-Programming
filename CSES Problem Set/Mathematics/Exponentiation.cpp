#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long int foo (long long int a, long long int b) {
	if (!b) return 1;
	long long res = foo(a, b / 2) % MOD;
	if (b % 2) return res % MOD * res % MOD * a % MOD;
	else return res * res % MOD;
}

void solve() {
	long long int a, b; cin >> a >> b;
	cout << foo(a, b) << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}