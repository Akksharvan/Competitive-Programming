#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long int N; cin >> N; long long int n = N; int res = 0;
	for (long long int p = 2; p * p <= N; p++) {
		int ret = 0; while (!(n % p)) { ret++; n /= p; }
		for (int i = 1; i <= ret; i++) { res++; ret -= i; }
	}

	if (n > 1) res++;
	cout << res << "\n"; return 0;
}