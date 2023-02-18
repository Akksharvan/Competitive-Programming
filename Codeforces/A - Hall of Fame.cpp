#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;

	vector<bool> trophies(n);

	int l = -1;
	for (int i = 1; i < n; i++) if (s[i] == 'L') l = i;

	int r = -1;
	for (int i = n - 1; i >= 0; i--) if (s[i] == 'R') r = i;

	if (l != -1) for (int i = l - 1; i >= 0; i--) trophies[i] = 1;
	if (r != -1) for (int i = r + 1; i < n; i++) trophies[i] = 1;

	bool illuminated = 1;
	for (bool b : trophies) if (!b) illuminated = 0;

	if (illuminated) cout << 0 << "\n";
	else {
		int index = -1;
		for (int i = 0; i < n - 1; i++) if (s[i] == 'L' && s[i + 1] == 'R') index = i + 1;
		cout << index << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) solve();

	return 0;
}