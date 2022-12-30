#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		if ((x+y) == 0 || (x > 0 && y > 0) || (n - 1) % (x + y) != 0) {
			cout << -1 << nl;
			continue;
		}
		else {
			for (int i = 1; i < n; i += max(x, y)) {
				for (int j = 0; j < max(x, y); j++) {
					cout << i + 1 << spc;
				}
			}
			cout << nl;
		}
	}

	return 0;
}