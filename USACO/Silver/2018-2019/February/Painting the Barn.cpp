#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<array<int, (int) 1e3 + 1>, (int) 1e3 + 1> B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		B[x1][y1]++;
		B[x1][y2]--;
		B[x2][y1]--;
		B[x2][y2]++;
	}

	int A = 0;
	for (int i = 0; i < (int) 1e3; i++) {
		for (int j = 0; j < (int) 1e3; j++) {
			if (i) {
				B[i][j] += B[i - 1][j];
			}

			if (j) {
				B[i][j] += B[i][j - 1];
			}

			if (i && j) {
				B[i][j] -= B[i - 1][j - 1];
			}

			if (B[i][j] == K) {
				A++;
			}
		}
	}

	cout << A << nl;
	return 0;
}