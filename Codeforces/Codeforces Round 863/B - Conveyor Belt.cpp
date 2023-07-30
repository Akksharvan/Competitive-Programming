#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	int c1 = min(min(abs(x1 - 1), abs(n - x1)), min(abs(y1 - 1), abs(n - y1)));
	int c2 = min(min(abs(x2 - 1), abs(n - x2)), min(abs(y2 - 1), abs(n - y2)));

	cout << abs(c2 - c1) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}