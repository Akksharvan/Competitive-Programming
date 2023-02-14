#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int &a : A) cin >> a;
	sort(begin(A), end(A));

	vector<vector<int>> dp(2, vector<int>(N));
	fill(begin(dp[0]), end(dp[0]), INT_MAX - 1); fill(begin(dp[1]), end(dp[1]), INT_MAX - 1);

	dp[0][0] = 0; dp[1][N - 1] = 0;
	int l = 0, r = N - 1;

	for (int i = 1; i < N; i++) {
		while (l + 1 < i && A[i] - A[l + 1] > dp[0][l + 1] + 1) l++;
		dp[0][i] = min(dp[0][l + 1] + 1, A[i] - A[l]);
	}
	

	for (int i = N - 2; i >= 0; i--) {
		while (r - 1 > i && A[r - 1] - A[i] > dp[1][r - 1] + 1) r--;
		dp[1][i] = min(dp[1][r - 1] + 1, A[r] - A[i]);
	}

	int i = 0, j = N - 1, res = INT_MAX;
	while (i < j) {
		res = min(res, max(A[j] - A[i], 2 + 2 * max(dp[0][i], dp[1][j])));
		if (dp[0][i + 1] < dp[1][j - 1]) { i++; } else { j--; }
	}
	
	cout << res / 2 << '.' << (res % 2 ? 5 : 0) << '\n';
	return 0;
}