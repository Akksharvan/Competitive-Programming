#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	array<array<array<int, (int) 5e2>, (int) 5e2>, 2> p{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int g;
			cin >> g;

			if (g > 100) {
				p[0][i][j] = 1;
				p[1][i][j] = 1;
			}
			else if (g == 100) {
				p[0][i][j] = 1;
			}
		}
	}

	array<long long int, 2> sums{};
	for (int s = 0; s < 2; s++) {
		for (int i = 0; i < N; i++) {
			array<int, (int) 5e2> tp;
			tp.fill(1);

			for (int j = i; j < N; j++) {
				for (int k = 0; k < N; k++) {
					tp[k] = tp[k] & p[s][j][k];
				}

				int run = 0;
				for (int l = 0 ; l < N; l++) {
					if (tp[l] == 1) {
						run++;
					} else {
						sums[s] += (run * (run + 1)) / 2;
						run = 0;
					}
				}
				sums[s] += (run * (run + 1)) / 2;
			}
		}
	}

	cout << sums[0] - sums[1] << nl;
	return 0;
}