#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int X, Y, M;
	cin >> X >> Y >> M;

	int res = INT_MIN;
	for (int i = 0; i <= M / X; i++) {
		int j = (M - (i * X)) / Y;
		res = max(res, i * X + j * Y);
	}

	cout << res << "\n";
	return 0;
}