// https://codeforces.com/gym/103643/problem/I

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, Q;
	cin >> N >> M >> Q;

	vector<vector<int>> A (N + 1, vector<int> (M + 1));
	vector<vector<vector<int>>> pA ((int) 3e1, vector<vector<int>> (N + 1, vector<int> (M + 1)));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	for (int n = 0; n < (int) 3e1; n++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				pA[n][i][j] = pA[n][i - 1][j] + pA[n][i][j - 1] - pA[n][i - 1][j - 1] + ((A[i][j] >> n) & 1);
			}
		}
	}

	for (int q = 0; q < Q; q++) {
		int x, y, X, Y, k = 0;
		cin >> x >> y >> X >> Y;

		for (int n = 0; n < (int) 3e1; n++) {
			int k_n = pA[n][X][Y] - pA[n][x - 1][Y] - pA[n][X][y - 1] + pA[n][x - 1][y - 1];

			if (k_n > 0) {
				k_n = 1;
			}
			
			k = (k_n << n) | k;
		}

		cout << k << nl;
	}

	return 0;
}