#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (int &i : A) cin >> i;

	vector<vector<int>> DP(3, vector<int> (N + 1));
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			DP[i][j] = DP[i][j - 1] + (A[j - 1] == (i + 1));
		}
	}

	for (int q = 0; q < Q; q++) {
		int A, B; cin >> A >> B;
		cout << (DP[0][B] - DP[0][A - 1]) << " ";
		cout << (DP[1][B] - DP[1][A - 1]) << " ";
		cout << (DP[2][B] - DP[2][A - 1]) << "\n";
	}

	return 0;
}
