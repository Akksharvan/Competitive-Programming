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
		int l, r, x, a, b;
		cin >> l >> r >> x >> a >> b;

		if (a == b) {
			cout << 0 << nl;
		}
		else if (a + x > r && a - x < l) {
			cout << -1 << nl;
		}
		else if (abs(a - b) >= x && (l <= b && b <= r)) {
			cout << 1 << nl;
		}
		else if (b - x < l && b + x > r) {
			cout << -1 << nl;
		}
		else if (abs(a - l) >= x && abs(b - l) >= x) {
			cout << 2 << nl;
		}
		else if (abs(a - r) >= x && abs(b - r) >= x) {
			cout << 2 << nl;
		}
		else {
			cout << 3 << nl;
		}
	}

	return 0;
}