#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("bcs.in", "r", stdin);
	freopen("bcs.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K; cin >> N >> K;
	vector<vector<char>> A(N, vector<char> (N));

	for (vector<char> &a : A) {
		for (char &c : a) cin >> c;
	}

	vector<vector<vector<char>>> B(K, vector<vector<char>> (N, vector<char> (N)));
	for (vector<vector<char>> &b : B) {
		for (vector<char> &a : b) {
			for (char &c : a) cin >> c;
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			for (int a = -N; a < N; a++) {
				for (int b = -N; b < N; b++) {
					for (int c = -N; c < N; c++) {
						for (int d = -N; d < N; d++) {
							bool g = 1; if (i == j) continue;

							for (int l = 0; l < N; l++) {
								for (int k = 0; k < N; k++) {
									if (B[i][l][k] == '#' && (l + a < 0 || l + a >= N || k + b < 0 || k + b >= N)) g = 0;
									if (B[j][l][k] == '#' && (l + c < 0 || l + c >= N || k + d < 0 || k + d >= N)) g = 0;
								}
							}

							if (!g) continue;
							g = 1; vector<vector<char>> C(N, vector<char> (N, '.'));

							for (int l = 0; l < N; l++) {
								for (int k = 0; k < N; k++) {
									if (B[i][l][k] == '#' && (l + a >= 0 && l + a < N && k + b >= 0 && k + b < N)) {
										if (C[l + a][k + b] == '#') g = 0;
										else C[l + a][k + b] = '#';
									}

									if (B[j][l][k] == '#' && (l + c >= 0 && l + c < N && k + d >= 0 && k + d < N)) {
										if (C[l + c][k + d] == '#') g = 0;
										else C[l + c][k + d] = '#';
									}
								}
							}

							if (g && i > j) { cout << (j + 1) << " " << (i + 1) << "\n"; return 0; }
							else if (g) { cout << (i + 1) << " " << (j + 1) << "\n"; return 0; }
						}
					}
				}
			}
		}
	}

	return 0;
}