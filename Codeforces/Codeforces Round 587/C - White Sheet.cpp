#include <bits/stdc++.h>
using namespace std;

pair<pair<int, int>, pair<int, int>> foo(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c, pair<int, int> &d) {
	int A, B, C, D;
	A = max(min(a.first, b.first), min(c.first, d.first));
	B = min(max(a.first, b.first), max(c.first, d.first));
	C = min(max(a.second, b.second), max(c.second, d.second));
	D = max(min(a.second, b.second), min(c.second, d.second));

	if (B <= A || C <= D) return { {0, 0}, {0, 0} };
	return { { A, D }, { B, C } };
}

long long int bar (pair<int, int> &a, pair<int, int> &b) { return (long long int) (1) * abs(a.first - b.first) * abs(a.second - b.second);}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<pair<int, int>> p(6);
	for (pair<int, int> &i : p) cin >> i.first >> i.second;

	pair<pair<int, int>, pair<int, int>> a = foo(p[0], p[1], p[2], p[3]);
	pair<pair<int, int>, pair<int, int>> b = foo(p[0], p[1], p[4], p[5]);
	pair<pair<int, int>, pair<int, int>> c = foo(a.first, a.second, b.first, b.second);

	if ( bar(p[0], p[1]) > bar(a.first, a.second) + bar(b.first, b.second) - bar(c.first, c.second)) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}