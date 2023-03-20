#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<int> A(N + 1); for (int i = 1; i <= N; i++) cin >> A[i];
	vector<vector<int>> DP(N + 1, vector<int> (K + 1, 0)); int ret = 0;

	for (int i = 1; i <= N; i++) {
		ret = max(ret, A[i]);
		DP[i][0] = ret * i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			DP[i][j] = INT_MAX; ret = A[i];
			for (int k = i - 1; k >= 0; k--) {
				DP[i][j] = min(DP[i][j], DP[k][j - 1] + ret * (i - k));
				ret = max(ret, A[k]);
			}
		}
	}

	cout << DP[N][K] - accumulate(begin(A), end(A), 0) << "\n";
	return 0;
}