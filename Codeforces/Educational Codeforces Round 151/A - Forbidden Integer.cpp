#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K, X; cin >> N >> K >> X;
	vector<vector<int>> DP(2, vector<int> (N + 1));
	
	vector<int> A; DP[1][0] = 1;
	for (int i = 1; i <= K; i++) {
		if (i == X) continue;
		A.push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		DP[1][i] = 0;
		for (int j : A) {
			if (i - j >= 0 && DP[1][i - j]) {
				DP[1][i] = 1;
				DP[0][i] = j;
				continue;
			}
		}
	}

	if (DP[1][N]) {
		cout << "Yes" << "\n";
		vector<int> B;

		while (N > 0) {
			B.push_back(DP[0][N]);
			N -= DP[0][N];
		}

		cout << size(B) << "\n";
		for (int &i : B) cout << i << " ";

		cout << "\n";
		return;
	}
	else cout << "No" << "\n";

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}