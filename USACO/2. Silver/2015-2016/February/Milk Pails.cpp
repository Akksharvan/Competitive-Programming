#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<array<array<bool, 101>, 101>, 101> visited;
int X, Y, K, M;

int answer = INT_MAX;
void next_operation (int CX, int CY, int CK) {
	if (visited[CX][CY][CK] || CK > K) return;

	visited[CX][CY][CK] = 1;
	answer = min(answer, abs(M - (CX + CY)));
	CK++;

	next_operation(0, CY, CK);
	next_operation(CX, 0, CK);

	next_operation(X, CY, CK);
	next_operation(CX, Y, CK);

	next_operation(CX + CY - min(Y, CY + CX), min(Y, CY + CX), CK);
	next_operation(min(X, CX + CY), CY + CX - min(X, CX + CY), CK);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	cin >> X >> Y >> K >> M;
	next_operation(0, 0, 0);

	cout << answer << nl;
	return 0;
}