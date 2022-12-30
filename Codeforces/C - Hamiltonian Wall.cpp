#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s1, s2;
		cin >> s1 >> s2;

		vector<int> r1(n), r2(n);
		for (int i = 0; i < n; i++) {
			if (s1[i] == 'B') {
				r1[i] = 0;
			}
			else {
				r1[i] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			if (s2[i] == 'B') {
				r2[i] = 0;
			}
			else {
				r2[i] = 1;
			}
		}

		vector<int> w(n);
		for (int i = 0; i < n; i++) {
			if (r1[i] == 0 && r2[i] == 0) {
				w[i] = 0;
			}
			else if (r1[i] == 0 && r2[i] == 1) {
				w[i] = 1;
			}
			else {
				w[i] = 2;
			}

			cerr << w[i] << nl;
		}

		int r, i = 0, b = 1;
		while (!w[i]) {
			i++;
		}

		if (w[i] == 1) {
			r = 0;
		}
		else {
			r = 1;
		}

		for (int j = i + 1; j < n; j++) {
			if (!r) {
				if (!w[j]) {
					r = !r;
				}
				else if (w[j] == 2) {
					b = 0;
					break;
				}
			}
			else {
				if (!w[j]) {
					r = !r;
				}
				else if (w[j] == 1) {
					b = 0;
					break;
				}
			}

		}
		if (b) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}