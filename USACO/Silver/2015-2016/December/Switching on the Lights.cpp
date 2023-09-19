#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

array<array<bool, (int) 1e2 + 1>, (int) 1e2 + 1> visited;
array<array<bool, (int) 1e2 + 1>, (int) 1e2 + 1> lit_rooms;
vector<vector<vector<pair<int, int>>>> switch_locations((int) 1e2 + 1, vector<vector<pair<int, int>>> ((int) 1e2 + 1));

void floodfill (int x, int y, int N, bool revisit) {
	if (x < 1 || x > N || y < 1 || y > N || !lit_rooms[x][y]) {
		return;
	}
	else if ((revisit && !visited[x][y]) || (!revisit && visited[x][y])) {
		return;
	}

	visited[x][y] = 1;

	for (const pair<int, int> &new_room : switch_locations[x][y]) {
		if (!lit_rooms[new_room.first][new_room.second]) {
			lit_rooms[new_room.first][new_room.second] = 1;

			floodfill(new_room.first - 1, new_room.second, N, 1);
			floodfill(new_room.first + 1, new_room.second, N, 1);
			floodfill(new_room.first, new_room.second - 1, N, 1);
			floodfill(new_room.first, new_room.second + 1, N, 1);
		}
	}

	floodfill(x - 1, y, N, 0);
	floodfill(x + 1, y, N, 0);
	floodfill(x, y - 1, N, 0);
	floodfill(x, y + 1, N, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switch_locations[x][y].push_back({a, b});
	}

	lit_rooms[1][1] = 1;
	floodfill(1, 1, N, 0);

	int lit_room_count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (lit_rooms[i][j]) {
				lit_room_count++;
			}
		}
	}

	cout << lit_room_count << nl;
	return 0;
}