#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	int A, B, C, D;
	A = min(x1, x3); B = max(x2, x4);
	C = max(y2, y4); D = min(y1, y3);

	int res = max(B - A, C - D) * max(B - A, C - D);
	cout << res << "\n"; return 0;
}