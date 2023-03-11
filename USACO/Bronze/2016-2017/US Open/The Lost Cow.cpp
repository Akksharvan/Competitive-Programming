#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int x, y; cin >> x >> y;
	int res = 0, a = 1, b = 1, c = x;

	while (true) {
		if (b == 1 && x <= y && y <= x + a) { res += abs(y - x); break; }
		if (b == - 1 && y <= x && x - a <= y) { res += abs(y - x); break; }
		res += a * 2; a *= 2; b *= -1;
	}

	cout << res << "\n";
	return 0;
}