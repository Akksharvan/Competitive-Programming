#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, C;
	cin >> N >> M >> C;

	vector<int> A(N); for (int &a : A) cin >> a;
	vector<vector<int>> adj(N); while (M--) { int a, b; cin >> a >> b; adj[--a].push_back(--b); }

	vector<vector<long long int>> dp(1001, vector<long long int>(N));
	for (vector<long long int> &d : dp) fill(begin(d), end(d), -1);

	long long int res = 0;
	dp[0][0] = 0;

	for (int d = 0; d < 1000; d++) {
		for (int i = 0; i < N; i++) {
			if (dp[d][i] != -1) {
				for (int u : adj[i]) {
					dp[d + 1][u] = max(dp[d + 1][u], dp[d][i] + A[u]);
				}
			}
		}

		res = max(res, (dp[d][0] - (C * d * d)));
	}

	cout << res << "\n";
	return 0;
}