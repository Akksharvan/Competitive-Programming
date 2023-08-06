#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N; cin >> N;

	vector<long long> A(N);
	for (long long &i : A) cin >> i;

	pair<long long, long long> DP[(int) 5e3][(int) 5e3];
	for (int i = 0; i < 5e3; i++) {
		for (int j = 0; j < 5e3; j++) {
			DP[i][j].first = 0;
			DP[i][j].second = 0;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			if (i == j) DP[i][j] = {A[i], 0};
			else {
				if (A[i] + DP[i + 1][j].second >= A[j] + DP[i][j - 1].second) DP[i][j] = {A[i] + DP[i + 1][j].second, DP[i + 1][j].first};
				else DP[i][j] = {A[j] + DP[i][j - 1].second, DP[i][j - 1].first};
			}
		}
	}

	cout << DP[0][N - 1].first << "\n";
	return 0;
}