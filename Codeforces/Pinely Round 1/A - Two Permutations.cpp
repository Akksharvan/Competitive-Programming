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
		int n, a, b;
		cin >> n >> a >> b;

		if (a > b) {
			swap(a, b);
		}

		if (a == b) {
			if (a + b >= n - 1 && a != n) {
				cout << "NO" << nl;
			}
			else {
				cout << "YES" << nl;
			}
		}
		else {
			if (n - a > b + 1) {
				cout << "YES" << nl;
			}
			else {
				cout << "NO" << nl;
			}
		}
	}

	return 0;
}