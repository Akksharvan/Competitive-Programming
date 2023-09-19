#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> R(N);
	for (int &r : R) cin >> r;

	long long int res = LLONG_MAX;
	for (int r = 0; r < N; r++) {
		vector<vector<long long int>> dp(N, vector<long long int>(N, LLONG_MAX));
		dp[0][0] = 0; for (int i = 1; i < N; i++) dp[0][i] = dp[0][i - 1] + (i * R[i]);

		for (int k = 1; k < K; k++) {
			for (int j = 0; j < N; j++) {
				dp[k][j] = dp[k - 1][j];
				long long int p = 0, pp = 0;

				for (int i = j; i >= 0; i--) {
					pp += p; p += R[i];
					dp[k][j] = min(dp[k][j], dp[k - 1][i - 1] + pp);
				}
			}
		}

		res = min(res, dp[K - 1][N - 1]);
		rotate(begin(R), begin(R) + 1, end(R));
	}

	cout << res << "\n";
	return 0;
}