#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, c = 0;
	cin >> n >> m;

	if (n > m) {
		cout << n - m << nl;
		return 0;
	}

	while (m != n) {
		if (m % 2 == 0 && m > n) {
			m = m / 2;
		}
		else {
			m++;
		}

		c++;
	}

	cout << c << nl;
	return 0;
}