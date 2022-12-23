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

	vector<array<int, 3>> original_cows(N);
	vector<vector<array<int, 3>>> cows(2);

	set<array<int, 5>> time_stamps;
	vector<int> cells_eaten(N);
	vector<bool> stuck(N);

	for (int i = 0; i < N; i++) {
		int x, y;
		char d;
		cin >> d >> x >> y;

		original_cows[i] = {x, y, i};
		if (d == 'N') {
			cows[0].push_back({x, y, i});
		}
		else if (d == 'E') {
			cows[1].push_back({x, y, i});
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < sz(cows[i]); j++) {

			if (i == 0) {
				for (int k = 0; k < sz(cows[1]); k++) {
					if (cows[i][j][0] >= cows[1][k][0] && cows[i][j][1] <= cows[1][k][1]) {
						int ht = abs(cows[i][j][0] - cows[1][k][0]);
						int vt = abs(cows[i][j][1] - cows[1][k][1]);
						int time = max(ht, vt);
						time_stamps.insert({time, i, j, 1, k});
					}
				}
			}
			else if (i == 1) {
				for (int k = 0; k < sz(cows[0]); k++) {
					if (cows[i][j][0] <= cows[0][k][0] && cows[i][j][1] >= cows[0][k][1]) {
						int ht = abs(cows[i][j][0] - cows[0][k][0]);
						int vt = abs(cows[i][j][1] - cows[0][k][1]);
						int time = max(ht, vt);
						time_stamps.insert({time, i, j, 0, k});
					}
				}
			}
		}
	}

	int time = 0, time_delta = 0;

	for (const array<int, 5>& time_stamp : time_stamps) {
		time_delta = time_stamp[0] - time;
		time = time_stamp[0];

		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				for (int k = 0; k < sz(cows[j]); k++) {
					if (!stuck[cows[j][k][2]]) {
						cows[j][k][1] += time_delta;
					}
				}
			}
			else if (j == 1) {
				for (int k = 0; k < sz(cows[j]); k++) {
					if (!stuck[cows[j][k][2]]) {
						cows[j][k][0] += time_delta;
					}
				}
			}
		}

		int d1 = time_stamp[1];
		int i1 = time_stamp[2];

		int d2 = time_stamp[3];
		int i2 = time_stamp[4];

		if (d1 == 0) {
			if (cows[d2][i2][0] > cows[d1][i1][0]) {
				stuck[cows[d1][i1][2]] = true;
			}
			else if (cows[d2][i2][0] < cows[d1][i1][0]) {
				stuck[cows[d2][i2][2]] = true;
			}
		}
		else if (d1 == 1) {
			if (cows[d2][i2][1] > cows[d1][i1][1]) {
				stuck[cows[d1][i1][2]] = true;
			}
			else if (cows[d2][i2][1] < cows[d1][i1][1]) {
				stuck[cows[d2][i2][2]] = true;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < sz(cows[i]); j++) {
			int ht = abs(cows[i][j][0] - original_cows[cows[i][j][2]][0]);
			int vt = abs(cows[i][j][1] - original_cows[cows[i][j][2]][1]);
			cells_eaten[cows[i][j][2]] = ht + vt;
		}
	}

	for (int i = 0; i < N; i++) {
		if (!stuck[i]) {
			cout << "Infinity" << nl;
		}
		else {
			cout << cells_eaten[i] << nl;
		}
	}

	return 0;
}