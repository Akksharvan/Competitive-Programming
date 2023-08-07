#include <bits/stdc++.h>
using namespace std;

int F (int I, int L, int H, vector<array<long long, 3>> &A) {
	while (L < H) {
		int M = L + (H - L) / 2;
		if (A[M][0] > I) H = M;
		else L = M + 1;
	}

	return H;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<array<long long, 3>> A(N);

	for (array<long long, 3> &i : A) cin >> i[0] >> i[1] >> i[2];
	sort(begin(A), end(A));
	
	long long DP[(int) 2e5 + 1];
	fill(begin(DP), end(DP), 0);

	for (int i = 0; i <= N; i++) {
		if (i > 0) DP[i] = max(DP[i], DP[i - 1]);
		if (i == N) continue;
		
		int X = F(A[i][1], 0, N, A);
		DP[X] = max(DP[X], DP[i] + A[i][2]);
	}

	cout << DP[N] << "\n"; 
	return 0;
}