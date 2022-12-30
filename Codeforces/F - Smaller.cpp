#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())
const char a = 'a';

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		long long int q, s = 0, t = 0, ss = 1, sss = 1, ts = 1, tgs = 1;
		cin >> q;

		while (q--) {
			int d, k;
			string x;
			cin >> d >> k >> x;

			for (const char& c : x) {
				if (d == 1) {
					if ((long long int) (c - a) == s) {
						sss += k;
					}

					ss += k;
 				}
				else if (d == 2) {
					if ((long long int) (c - a) > t) {
						t = (long long int) (c - a);
						tgs = k;
					}
					else if ((long long int) (c - a) == t) {
						tgs += k;
					}

					ts += k;
				}
			}

			if (s < t) {
				cout << "YES" << nl;
			}
			else if (s == t && sss < tgs && ss == sss) {
				cout << "YES" << nl;
			}
			else {
				cout << "NO" << nl;
			}
		}
	}

	return 0;
}