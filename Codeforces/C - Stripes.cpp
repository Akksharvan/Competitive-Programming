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
		bool red = false;
		for (int i = 0; i < 8; i++) {
			string stripe;
			cin >> stripe;

			if (stripe == "RRRRRRRR") {
				red = true;
			}
		}

		if (red) {
			cout << 'R' << nl;
		}
		else {
			cout << 'B' << nl;
		}
	}

	return 0;
}