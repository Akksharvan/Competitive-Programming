#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<array<int, 1001>, 1001> farm;
array<array<int, 1001>, 1001> prefix_farm;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int N;
	cin >> N;

	vector<pair<int, int>> cow_locations;
	vector<int> x_locations;
	vector<int> y_locations;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		cow_locations.push_back({x, y});
		x_locations.push_back(x);
		y_locations.push_back(y);
	}

	sort(x_locations.begin(), x_locations.end());
	sort(y_locations.begin(), y_locations.end());

	unique(x_locations.begin(), x_locations.end());
	unique(y_locations.begin(), y_locations.end());

	map<int, int> x_map;
	map<int, int> y_map;

	for (int i = 0; i < sz(x_locations); i++) {
		x_map[x_locations[i]] = i + 1;
	}

	for (int i = 0; i < sz(y_locations); i++) {
		y_map[y_locations[i]] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		int x = x_map[cow_locations[i].first];
		int y = y_map[cow_locations[i].second];

		farm[x][y] = 1;
	} 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prefix_farm[i][j] = prefix_farm[i - 1][j] + prefix_farm[i][j - 1] - prefix_farm[i - 1][j - 1] + farm[i][j];
		}
	}

	int M = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a1 = 1, b1 = 1, A1 = i, B1 = j;
			int a2 = i + 1, b2 = 1, A2 = N, B2 = j;
			int a3 = 1, b3 = j + 1, A3 = i, B3 = N;
			int a4 = i + 1, b4 = j + 1, A4 = N, B4 = N;

			int q1 = prefix_farm[A1][B1] - prefix_farm[a1 - 1][B1] - prefix_farm[A1][b1 - 1] + prefix_farm[a1 - 1][b1 - 1];
			int q2 = prefix_farm[A2][B2] - prefix_farm[a2 - 1][B2] - prefix_farm[A2][b2 - 1] + prefix_farm[a2 - 1][b2 - 1];
			int q3 = prefix_farm[A3][B3] - prefix_farm[a3 - 1][B3] - prefix_farm[A3][b3 - 1] + prefix_farm[a3 - 1][b3 - 1];
			int q4 = prefix_farm[A4][B4] - prefix_farm[a4 - 1][B4] - prefix_farm[A4][b4 - 1] + prefix_farm[a4 - 1][b4 - 1];

			int t1 = max(q1, q2);
			int t2 = max(q3, q4);

			M = min(M, max(t1, t2));
		}
	}

	cout << M << nl;
	return 0;
}