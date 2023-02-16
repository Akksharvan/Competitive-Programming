#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long int x, y;
	cin >> x >> y;

	if (x == y) cout << (x * y - (x - 1)) << "\n";
	else if (x > y) {
		if (x % 2) cout << ((x - 1) * (x - 1) + y) << "\n";
		else cout << (x * x - (y - 1)) << "\n";
	}
	else {
		if (y % 2) cout << (y * y - (x - 1)) << "\n";
		else cout << ((y - 1) * (y - 1) + x) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}