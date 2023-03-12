#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);

	int a, b, x, y; cin >> a >> b >> x >> y;
	cout << min(abs(a - b), min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x))) << "\n"; return 0;
}