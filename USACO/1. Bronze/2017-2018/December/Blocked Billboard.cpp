#include <bits/stdc++.h>
using namespace std;

struct Rectangle { int x1, y1, x2, y2; int area() { return (y2 - y1) * (x2 - x1); } };
int foo(Rectangle &a, Rectangle &b) { return max(0, min(a.x2, b.x2) - max(a.x1, b.x1)) * max(0, min(a.y2, b.y2) - max(a.y1, b.y1));}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	Rectangle A, B, C; cin >> A.x1 >> A.y1 >> A.x2 >> A.y2 >> B.x1 >> B.y1 >> B.x2 >> B.y2 >> C.x1 >> C.y1 >> C.x2 >> C.y2;
	cout << A.area() + B.area() - foo(A, C) - foo(B, C) << "\n"; return 0;
}