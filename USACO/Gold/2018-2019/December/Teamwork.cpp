#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<int> A(N); for (int &a : A) cin >> a;
	vector<int> DP(N); DP[0] = A[0];

	for (int i = 1; i < N; i++) {
		int res = A[i];
		for (int j = i; j >= 0 && i + 1 - j <= K; j--) {
			res = max(res, A[j]);
			if (!j) DP[i] = max(DP[i], res * (i + 1 - j));
			else DP[i] = max(DP[i], DP[j - 1] + res * (i + 1 - j));
		}
	}
	cout << DP[N - 1] << "\n";
	return 0;
}