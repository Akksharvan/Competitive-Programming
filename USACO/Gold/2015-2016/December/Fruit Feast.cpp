#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);

	int T, A, B;
	cin >> T >> A >> B;

	vector<vector<bool>> DP(2, vector<bool> (T + 1));
	priority_queue<int, vector<int>, greater<int>> Q;

	DP[0][0] = 1; DP[1][0] = 1;
	DP[0][A] = 1; DP[0][B] = 1;

	for (int i = 0; i <= T; i++) {
		if (!DP[0][i]) continue;
		if (i + A <= T) DP[0][i + A] = 1;
		if (i + B <= T) DP[0][i + B] = 1;
		DP[1][i / 2] = 1;
	}

	for (int i = 0; i <= T; i++) {
		if (!DP[1][i]) continue;
		if (i + A <= T) DP[1][i + A] = 1;
		if (i + B <= T) DP[1][i + B] = 1;
	}

	int res = INT_MIN;
	for (int i = 0; i <= T; i++) if (DP[0][i] || DP[1][i]) res = i;

	cout << res << "\n";
	return 0;
}