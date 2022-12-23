#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int p = 0;
array<array<char, (int) 5e1>, (int) 5e1> pasture;

void floodfill(int y, int x, int d, int N, int t, int mt) {
	if (x >= N || y >= N || pasture[y][x] == 'H' || t > mt) {
		return;
	}

	if (x == N - 1 && y == N - 1) {
		p++;
		return;
	}
	
	if (d) {
		floodfill(y + 1, x, d, N, t, mt);
		floodfill(y, x + 1, !d, N, t + 1, mt);
	}
	else {
		floodfill(y, x + 1, d, N, t, mt);
		floodfill(y + 1, x, !d, N, t + 1, mt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N, K;
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			string path;
			cin >> path;

			for (int j = 0; j < N; j++) {
				pasture[i][j] = path[j];
			}
		}

		p = 0;
		floodfill(1, 0, 1, N, 0, K);
		floodfill(0, 1, 0, N, 0, K);
		cout << p << nl;
	}

	return 0;
}