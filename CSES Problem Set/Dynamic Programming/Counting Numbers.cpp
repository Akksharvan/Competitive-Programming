#include <bits/stdc++.h>
using namespace std;

long long DP[20][10][2][2];

long long F (string &A, long long N, long long B, bool C, bool D) {
	if (!N) return 1;
	else if (N == size(A)) memset(DP, -1, sizeof(DP));
	
	if (B != -1 && DP[N][B][C][D] != -1) return DP[N][B][C][D];
	long long R = 0, E = ((C) ? (A[size(A) - N] - '0') : (9));

	for (int i = 0; i <= E; i++) {
		if (i == B && !D) continue;
		R += F(A, N - 1, i, (C && i == E), (D && !i));
	}

	DP[N][B][C][D] = R;
	return R;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);

	long long C, D; cin >> C >> D;
	string A = to_string(C - 1), B = to_string(D);

	cout << (F(B, size(B), -1, 1, 1) - F(A, size(A), -1, 1, 1)) << "\n";
	return 0;
}