#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<array<char, (int) 1e3>, (int) 1e3> ice_cream_output;
array<array<bool, (int) 1e3>, (int) 1e3> visited;
int max_dimensions, current_size = 0, current_perimeter = 0;

bool floodfill(int r, int c) {
	if ((r < 0 || r >= max_dimensions || c < 0 || c >= max_dimensions) || ice_cream_output[r][c] != '#') {
		return true;
	}
	else if (visited[r][c]) {
		return false;
	}

	visited[r][c] = true;
	current_size++;

	current_perimeter += floodfill(r - 1, c) + floodfill(r + 1, c) + floodfill(r, c - 1) + floodfill(r, c + 1);
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	cin >> max_dimensions;

	for (int i = 0; i < max_dimensions; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < max_dimensions; j++) {
			ice_cream_output[i][j] = s[j];
		}
	}

	pair<int, int> dimensions = {0, 0};

	for (int i = 0; i < max_dimensions; i++) {
		for (int j = 0; j < max_dimensions; j++) {
			if (!visited[i][j]) {
				current_size = 0, current_perimeter = 0;
				floodfill(i, j);

				if (current_size > dimensions.first) {
					dimensions.first = current_size;
					dimensions.second = current_perimeter;
				}
				else if (current_size == dimensions.first) {
					dimensions.second = min(dimensions.second, current_perimeter);
				}
			}
		}
	}

	cout << dimensions.first << spc << dimensions.second << nl;
	return 0;
}
