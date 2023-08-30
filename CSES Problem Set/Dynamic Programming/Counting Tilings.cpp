#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

bool B (long long i, long long j, long long N) {
	for (long long k = 0; k < N; k++) {
		if ((i & (1 << k)) && (j & (1 << k))) return 0;
		if ((i & (1 << k)) && !(j & (1 << k))) continue;

		if (!(i & (1 << k)) && (j & (1 << k))) continue;
		if (!(i & (1 << k)) && !(j & (1 << k))) {
			int l = k;
			while ((k + 1) < N && (!(i & (1 << (k + 1))) && !(j & (1 << (k + 1))))) k++;
			
			if ((k - l + 1) % 2) return 0;
			else continue;
		}
	}

	return 1;
}

long long C (long long i, long long N) {
	for (long long j = 0; j < N; j++) {
		if (i & (1 << j)) continue;
		
		int k = j;
		while ((j + 1) < N && (!(i & (1 << (j + 1))))) j++;

		if ((j - k + 1) % 2) return 0;
		else continue;
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	long long N, M; cin >> N >> M;
	vector<vector<long long>> A((1 << N));

	for (long long i = 0; i < (1 << N); i++) {
		for (long long j = 0; j < (1 << N); j++) {
			if (!B(i, j, N)) continue;
			else A[i].push_back(j);
		}
	}

	long long DP[1000][1 << 10]; for (int i = 0; i < 1000; i++) fill(begin(DP[i]), end(DP[i]), 0);
	for (long long i = 0; i < (1 << N); i++) DP[0][i] = C(i, N);

	for (long long i = 1; i < M; i++) {
		for (long long j = 0; j < (1 << N); j++) {
			for (long long &k : A[j]) {
				DP[i][j] += DP[i - 1][k];
				DP[i][j] %= MOD;
			}
		}
	}

	cout << DP[M - 1][0] << "\n";
	return 0;
}