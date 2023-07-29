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

	string Y = "Yes";

	for (int i = 0; i < 17; i++) {
		Y += Y;
	}

	while (t--) {
		string y;
		cin >> y;

		int s = sz(y);
		string ss1 = Y.substr(0, s);
		string ss2 = Y.substr(1, s);
		string ss3 = Y.substr(2, s);

		if (y == ss1 || y == ss2 || y == ss3) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}