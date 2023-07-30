#include <bits/stdc++.h>
using namespace std;

void solve() {
	int res = 1; string s; cin >> s;
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[0] == '0') {
			res = 0;
			break;
		}

		if (s[i] == '?') {
			if (i == 0) res *= 9;
			else res *= 10;
		}
	}

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}