#include <bits/stdc++.h>
using namespace std;

const int MOD = (int) (1e9 + 7);

void read (__int128 &x) {
	int n;
	cin >> n;
	x = n;
}

string __int128s (__int128 x) {
	string ret;
	while (x > 0) ret += to_string((int) x % 10), x /= 10;
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		__int128 n;
		read(n);

		__int128 ret = 2022 * (((n * (n + 1) * (2 * n + 1)) / 6) + ((n * (n + 1) * (2 * n + 1)) / 6) - ((n * (n + 1)) / 2));
		cout << __int128s(ret % MOD) << "\n";
	}

	return 0;
}