#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K; cin >> N >> K;
	vector<int> A(N); for (int &i : A) cin >> i;
	vector<int> B(N); for (int &i : B) cin >> i;

	vector<int> DP(N + 1);
	for (int i = 1; i <= N; i++) {
		DP[i] += DP[i - 1];
		if (!B[i - 1]) DP[i] += A[i - 1];
	}

	int R = 0, C = 0; for (int i = 0; i < N; i++) if (B[i]) R += A[i];
	for (int i = 1; i <= N - K + 1; i++) {
		C = max(C, DP[i + K - 1] - DP[i - 1]);
	}

	cout << (R + C) << "\n";
	return 0;
}