#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s;
	cin >> n >> s;

	while ((int) s.size() > 1) {
		if (s[0] == '1' && s[(int) s.size() - 1] == '0') s = s.substr(1, (int) s.size() - 2);
		else if (s[0] == '0' && s[(int) s.size() - 1] == '1') s = s.substr(1, (int) s.size() - 2);
		else break;
	}

	cout << ((int) s.size()) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}