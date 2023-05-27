#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	if (count(begin(s), end(s), s[0]) == (int) s.size()) cout << -1 << "\n";
	else cout << ((int) s.size() - 1) << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}