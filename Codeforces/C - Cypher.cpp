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
		int n;
		cin >> n;

		vector<int> w(n);
		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}

		for (int& p : w) {
			int b, tt = 0;
			string s;
			cin >> b >> s;

			for (const char& c : s) {
				if (c == 'U') {
					tt--;
				}
				else {
					tt++;
				}
			}

			p += tt;
			while (p < 0) {
				p += 10;
			}

			cout << p % 10 << spc;
		}

		cout << nl;
	}

	return 0;
}