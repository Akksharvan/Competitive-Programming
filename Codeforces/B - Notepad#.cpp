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

		string s;
		cin >> s;

		map<string, int> pc;
		bool y = false;

		for (int i = 0; i < n - 1; i++) {
			string s_i = s.substr(i, 2);

			if (pc[s_i] >= 2 || pc[s_i] == 1 && s.substr(i - 1, 2) != s_i) {
				y = true;
				break;
			}
			else {
				pc[s_i]++;
			}
		}

		if (y) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}