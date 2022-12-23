#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	
	int N, B;
	cin >> N >> B;

	vector<int> tiles(N);
	set<int> indices;
	vector<int> indices_by_depth;

	for (int i = 0; i < N; i++) {
		cin >> tiles[i];
	}

	for (int i = 0; i < N; i++) {
		indices.insert(i);
		indices_by_depth.push_back(i);
	}

	sort(indices_by_depth.begin(), indices_by_depth.end(), [&](int x, int y) { return tiles[x] > tiles[y]; });

	vector<array<int, 3>> snowboots(B);
	for (int i = 0; i < B; i++) {
		cin >> snowboots[i][0] >> snowboots[i][1];
		snowboots[i][2] = i;
	}

	sort(snowboots.rbegin(), snowboots.rend());

	vector<bool> answer_key(B);
	int tile_depth_index = 0, max_gap = 1;
	for (const array<int, 3>& b : snowboots) {
		while (tile_depth_index < sz(indices_by_depth) && tiles[indices_by_depth[tile_depth_index]] > b[0]) {
			max_gap = max(max_gap, (*(next(indices.find(indices_by_depth[tile_depth_index]))) - *(prev(indices.find(indices_by_depth[tile_depth_index])))));
			indices.erase(indices_by_depth[tile_depth_index]);
			tile_depth_index++;
		}

		if (max_gap > b[1]) {
			answer_key[b[2]] = 0;
		}
		else {
			answer_key[b[2]] = 1;
		}
	}

	for (const bool& b : answer_key) {
		cout << b << nl;
	}
	
	return 0;
}