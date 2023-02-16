#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;

	if (a > 2 * b || b > 2 * a) { cout << "NO" << "\n"; return; }
	a %= 3, b %= 3; if (a < b) swap(a, b);
	
	if ((a == 0 && b == 0) || (a == 2 && b == 1)) { cout << "YES" << "\n"; return; }
	cout <<  "NO" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}