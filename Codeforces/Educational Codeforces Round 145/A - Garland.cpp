#include <bits/stdc++.h>
using namespace std;

void solve() {
	array<char, 4> a; for (int i = 0; i < 4; i++) cin >> a[i];
	sort(begin(a), end(a));

	if (a[0] == a[3]) cout << -1 << "\n";
	else if (a[1] == a[3] || a[0] == a[2]) cout << 6 << "\n";
	else cout << 4 << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}