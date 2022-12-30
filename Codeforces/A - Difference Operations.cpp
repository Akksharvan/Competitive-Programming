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
		int n;
		cin >> n;

		vector<int> a_n(n);
		for (int i = 0; i < n; i++) {
			cin >> a_n[i];
		}

		bool possible = true;

		for (int i = 1; i < n; i++) {
			if (a_n[i] % a_n[0] != 0) {
				possible = false;
				break;
			}
		}

		if (possible) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}