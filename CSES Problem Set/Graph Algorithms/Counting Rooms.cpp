#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<array<char, 1000>, 1000> building;
array<array<bool, 1000>, 1000> visited;
int n, m, rooms = 0;

void floodfill(int row, int col) {
	if ((row < 0 || row >= n || col < 0 || col >= m) || building[row][col] == '#' || visited[row][col]) {
		return;
	}

	visited[row][col] = true;

	floodfill(row, col + 1);
	floodfill(row, col - 1);
	floodfill(row + 1, col);
	floodfill(row - 1, col);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			building[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (building[i][j] == '.') {
					rooms++;
				}

				floodfill(i, j);
			}
		}
	}

	cout << rooms << nl;
	return 0;
}