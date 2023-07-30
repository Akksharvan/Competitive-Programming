#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
 
	long long N, M; cin >> N >> M;
	vector<long long> A(N); for (long long &i : A) cin >> i;
 
	vector<vector<long long>> DP(N, vector<long long> (M + 2));
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			if (A[i] == 0) { for (int j = 1; j <= M; j++) { DP[i][j] = 1; } }
			else DP[i][A[i]] = 1; continue;
		}
 
		if (A[i] == 0) {
			if (A[i - 1] == 0) { for (int j = 1; j <= M; j++) { DP[i][j] = ((DP[i - 1][j - 1] + DP[i - 1][j] + DP[i - 1][j + 1]) % MOD); } }
			else { for (int j = max(A[i - 1] - 1, 1LL); j <= min(A[i - 1] + 1, M); j++) { DP[i][j] = ((DP[i - 1][j - 1] + DP[i - 1][j] + DP[i - 1][j + 1]) % MOD); } }
		}
		else DP[i][A[i]] = ((DP[i - 1][A[i] - 1] + DP[i - 1][A[i]] + DP[i - 1][A[i] + 1]) % MOD);
	}
 
	long long R = 0; for (int j = 1; j <= M; j++) { R += DP[N - 1][j]; R %= MOD; }
	cout << R << "\n"; return 0;
}