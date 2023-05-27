#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	a += 1e8, b += 1e8, c += 1e8, d += 1e8;
	int i = c - a, j = d - b;

	cerr << a << " " << b << " " << c << " " << d << "\n";
	
	if (j < 0 || i > j) cout << -1 << "\n";
	else cout << j + (j - i) << "\n";
	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}