#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K; cin >> N >> K; vector<int> A(N);
	for (int &a : A) { char c; cin >> c; a = ((c == 'H') ? 0 : ((c == 'P') ? 1 : 2)); }

	vector<vector<vector<int>>> DP(N + 1, vector<vector<int>> (K + 2, vector<int> (3)));
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k < 3; k++) {
				if (k == A[i]) DP[i][j][k]++;
				DP[i + 1][j + 1][0] = max(DP[i + 1][j + 1][0], DP[i][j][k]);
				DP[i + 1][j + 1][1] = max(DP[i + 1][j + 1][1], DP[i][j][k]);
				DP[i + 1][j + 1][2] = max(DP[i + 1][j + 1][2], DP[i][j][k]);
				DP[i + 1][j][k] = max(DP[i + 1][j][k], DP[i][j][k]);
			}
		}
	}

	int res = 0; for (int k = 0; k < 3; k++) res = max(res, DP[N - 1][K][k]);
	cout << res << "\n";

	return 0;
}