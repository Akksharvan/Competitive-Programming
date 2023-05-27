#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	
	if ((int) s.size() <= 10) cout << s << "\n";
	else cout << s[0] << (int) s.size() - 2 << s[(int) s.size() - 1] << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}