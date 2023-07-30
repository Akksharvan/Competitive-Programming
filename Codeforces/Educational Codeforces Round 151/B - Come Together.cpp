#include <bits/stdc++.h>
using namespace std;

void solve() {
	int X1, Y1, X2, Y2, X3, Y3;
	cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;

	int R = 1;

	if (X2 > X1 && X3 > X1) R += min(X2 - X1, X3 - X1);
	else if (X2 < X1 && X3 < X1) R += min(X1 - X2, X1 - X3);

	if (Y2 > Y1 && Y3 > Y1) R += min(Y2 - Y1, Y3 - Y1);
	else if (Y2 < Y1 && Y3 < Y1) R += min(Y1 - Y2, Y1 - Y3);

	cout << R << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}