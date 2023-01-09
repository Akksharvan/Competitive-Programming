#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, B;
	cin >> N >> B;

	set<int> tiles;
	priority_queue<pair<int, int>> depths;

	for (int i = 0; i < N; i++) {
		int depth; cin >> depth;
		tiles.insert(i); depths.push({depth, i});
	}

	priority_queue<array<int, 3>> boots;
	for (int i = 0; i < B; i++) {
		int depth, step; cin >> depth >> step;
		boots.push({depth, step, i});
	}

	int max_step = 1;
	vector<bool> viable(B);

	while (!boots.empty()) {
		while (depths.top().first > boots.top()[0]) {
			max_step = max(max_step, *(next(tiles.find(depths.top().second))) - *(prev(tiles.find(depths.top().second))));
			tiles.erase(depths.top().second);
			depths.pop();
		}

		if (boots.top()[1] >= max_step) viable[boots.top()[2]] = 1;
		boots.pop();
	}

	for (bool v : viable) cout << v << "\n";
	return 0;
}