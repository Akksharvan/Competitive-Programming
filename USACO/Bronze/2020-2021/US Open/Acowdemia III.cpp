#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	array<array<char, (int) 1e3>, (int) 1e3> pasture;
	set<pair<int, int>> grass_locations;
	set<pair<int, int>> cow_locations;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;

		for (int j = 0; j < M; j++) {
			pasture[i][j] = row[j];

			if (pasture[i][j] == 'G') {
				grass_locations.insert({i, j});
			}
			else if (pasture[i][j] == 'C') {
				cow_locations.insert({i, j});
			}
		}
	}

	set<pair<pair<int, int>, pair<int, int>>> bovine_friendships;
	int bovine_friendships_count = 0;

	for (const pair<int, int>& grass_location : grass_locations) {
		vector<pair<int, int>> adjacent_cows;

		if (cow_locations.count({grass_location.first - 1, grass_location.second})) {
			adjacent_cows.push_back({grass_location.first - 1, grass_location.second});
		}

		if (cow_locations.count({grass_location.first + 1, grass_location.second})) {
			adjacent_cows.push_back({grass_location.first + 1, grass_location.second});
		}

		if (cow_locations.count({grass_location.first, grass_location.second - 1})) {
			adjacent_cows.push_back({grass_location.first, grass_location.second - 1});
		}

		if (cow_locations.count({grass_location.first, grass_location.second + 1})) {
			adjacent_cows.push_back({grass_location.first, grass_location.second + 1});
		}

		if (sz(adjacent_cows) == 2) {
			if (!bovine_friendships.count({adjacent_cows[0], adjacent_cows[1]}) && !bovine_friendships.count({adjacent_cows[1], adjacent_cows[0]})) {
				bovine_friendships.insert({adjacent_cows[0], adjacent_cows[1]});
			}
		}
		else if (sz(adjacent_cows) > 2) {
			bovine_friendships_count++;
		}
	}

	cout << sz(bovine_friendships) + bovine_friendships_count << nl;
	return 0;
}