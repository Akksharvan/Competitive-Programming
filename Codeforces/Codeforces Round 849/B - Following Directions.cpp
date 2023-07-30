#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s; cin >> n >> s;
	int x = 0, y = 0; bool YES = 0;

	for (char &c : s) {
		if (c == 'R') x++;
		else if (c == 'U') y++;
		else if (c == 'L') x--;
		else y--;

		if (x == 1 && y == 1) YES = 1;
	}
	
	cout << ((YES) ? "YES" : "NO") << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}