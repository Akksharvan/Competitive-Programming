#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, W; cin >> H >> W;
	vector<string> S(H); for (string &s : S) cin >> s;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == 's') {
				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++) {
						if ((i + x) >= 0 && (i + x) < H && (j + y) >= 0 && (j + y) < W && S[i + x][j + y] == 'n') {
							if ((i + (2 * x)) >= 0 && (i + (2 * x)) < H && (j + (2 * y)) >= 0 && (j + (2 * y)) < W && S[i + (2 * x)][j + (2 * y)] == 'u') {
								if ((i + (3 * x)) >= 0 && (i + (3 * x)) < H && (j + (3 * y)) >= 0 && (j + (3 * y)) < W && S[i + (3 * x)][j + (3 * y)] == 'k') {
									if ((i + (4 * x)) >= 0 && (i + (4 * x)) < H && (j + (4 * y)) >= 0 && (j + (4 * y)) < W && S[i + (4 * x)][j + (4 * y)] == 'e') {
										cout << (i + 1) <<  " " << (j + 1) << "\n";
										cout << (i + 1) + x <<  " " << (j + 1) + y << "\n";
										cout << (i + 1) + (2 * x) <<  " " << (j + 1) + (2 * y) << "\n";
										cout << (i + 1) + (3 * x) <<  " " << (j + 1) + (3 * y) << "\n";
										cout << (i + 1) + (4 * x) <<  " " << (j + 1) + (4 * y) << "\n";
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}