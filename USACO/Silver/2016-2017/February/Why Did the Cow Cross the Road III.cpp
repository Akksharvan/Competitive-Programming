#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<array<int, (int) 1e2>, (int) 1e2> fields;
array<array<bool, (int) 1e2>, (int) 1e2> visited;

set<pair<pair<int, int>, pair<int, int>>> roads;
set<pair<pair<int, int>, pair<int, int>>> distant_cows;

void floodfill (int r, int c, int pr, int pc, int N) {
	if (r < 0 || r >= N || c < 0 || c >= N) {
		return;
	}
	else if (roads.count({{r, c}, {pr, pc}}) || roads.count({{pr, pc}, {r, c}})) {
		return;
	}
	else if (visited[r][c]) {
		return;
	}

	visited[r][c] = true;
	floodfill(r - 1, c, r, c, N);
	floodfill(r + 1, c, r, c, N);
	floodfill(r, c - 1, r, c, N);
	floodfill(r, c + 1, r, c, N);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);


	int N, K, R;
	cin >> N >> K >> R;

	for (int i = 0; i < R; i++) {
		pair<int, int> field_one, field_two;
		cin >> field_one.first >> field_one.second;
		cin >> field_two.first >> field_two.second;

		field_one.first--, field_one.second--;
		field_two.first--, field_two.second--;

		roads.insert({field_one, field_two});
	}

	vector<pair<int, int>> cow_locations(K);
	for (pair<int, int>& cow_location : cow_locations) {
		cin >> cow_location.first >> cow_location.second;
		cow_location.first--, cow_location.second--;
	}

	for (pair<int, int>& cow_location : cow_locations) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}

		floodfill (cow_location.first, cow_location.second, cow_location.first, cow_location.second, N);
		for (pair<int, int>& cow_location_second : cow_locations) {
			if (!visited[cow_location_second.first][cow_location_second.second]) {
				distant_cows.insert({{cow_location.first, cow_location.second}, {cow_location_second.first, cow_location_second.second}});
			}
		}
	}

	cout << sz(distant_cows) / 2 << nl;
	return 0;
}