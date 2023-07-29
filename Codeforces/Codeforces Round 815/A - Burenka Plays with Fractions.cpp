#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long int a, b, c, d;
		cin >> a >> b >> c >> d;

		a = a * d;
		c = c * b;

		if (a == c) {
			cout << 0 << nl;
		}
		else if (a == 0 || c == 0 || max(a, c) % min(a, c) == 0) {
			cout << 1 << nl;
		}
		else {
			cout << 2 << nl;
		}
	}

	return 0;
}