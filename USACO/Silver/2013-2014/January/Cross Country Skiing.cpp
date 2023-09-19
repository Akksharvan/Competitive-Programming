#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<array<int, (int) 5e2>, (int) 5e2> ski_course_elevations;
array<array<int, (int) 5e2>, (int) 5e2> ski_course_waypoints;
array<array<bool, (int) 5e2>, (int) 5e2> visited;
int row_size, col_size, waypoint_counter = 0;

void floodfill(int r, int c, int pr, int pc, int d) {
	if ((r < 0 || r >= row_size || c < 0 || c >= col_size) || visited[r][c]) {
		return;
	}

	int difference = abs(ski_course_elevations[r][c] - ski_course_elevations[pr][pc]);
	if (difference > d) {
		return;
	}

	visited[r][c] = true;
	waypoint_counter += ski_course_waypoints[r][c];

	floodfill(r - 1, c, r, c, d);
	floodfill(r + 1, c, r, c, d);
	floodfill(r, c - 1, r, c, d);
	floodfill(r, c + 1, r, c, d);

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);

	cin >> row_size >> col_size;

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			cin >> ski_course_elevations[i][j];
		}
	}

	pair<int, int> waypoint;
	int total_waypoints = 0;

	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			cin >> ski_course_waypoints[i][j];

			if (ski_course_waypoints[i][j]) {
				total_waypoints++;
				waypoint.first = i;
				waypoint.second = j;
			}
		}
	}

	int start = 0, end = 1e9, rating = 1e9;
	while (start < end) {
		int mid = start + (end - start)/2;
		waypoint_counter = 0;

		for (int i = 0; i < row_size; i++) {
			for (int j = 0; j < col_size; j++) {
				visited[i][j] = false;
			}
		}

		floodfill(waypoint.first, waypoint.second, waypoint.first, waypoint.second, mid);
		if (waypoint_counter == total_waypoints) {
			rating = mid;
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}

	cout << rating << nl;
	return 0;
}
