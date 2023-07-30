#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N; int V = 1;
	vector<vector<int>> DP(N + 5, vector<int>(4));

	DP[1][0] = 0, DP[1][1] = 1;
	DP[1][2] = 1, DP[1][3] = 1;

	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		if (c == '+') {
			V++; int v, x;
			cin >> v >> x;

			DP[V][0] = min(DP[v][0], min(DP[v][1] + x, x));
			DP[V][1] = min(DP[v][1] + x, x);

			DP[V][2] = max(DP[v][2], max(DP[v][3] + x, x));
			DP[V][3] = max(DP[v][3] + x, x);
		}

		if (c == '?') {
			int u, v, k;
			cin >> u >> v >> k;
			if (DP[v][0] <= k && k <= DP[v][2]) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}