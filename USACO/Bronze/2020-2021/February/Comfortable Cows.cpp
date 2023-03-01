#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

set<pair<int, int>> cows, comfortable_cows;
bool is_comfortable(int x, int y) {
	if (x < 0 || x > 1000 || y < 0 || y > 1000) {
		return false;
	}

	int adjacent_cows = 0;
	adjacent_cows += cows.count({x + 1, y});
	adjacent_cows += cows.count({x - 1, y});
	adjacent_cows += cows.count({x, y + 1});
	adjacent_cows += cows.count({x, y - 1});

	if (adjacent_cows == 3) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		cows.insert({x, y});

		if (is_comfortable(x, y)) {
			comfortable_cows.insert({x, y});
		}

		if (is_comfortable(x + 1, y) && cows.count({x + 1, y})) {
			comfortable_cows.insert({x + 1, y});
		}
		else if (comfortable_cows.count({x + 1, y})) {
			comfortable_cows.erase({x + 1, y});
		}
	
		if (is_comfortable(x - 1, y) && cows.count({x - 1, y})) {
			comfortable_cows.insert({x - 1, y});
		}
		else if (comfortable_cows.count({x - 1, y})) {
			comfortable_cows.erase({x - 1, y});
		}

		if (is_comfortable(x, y + 1) && cows.count({x, y + 1})) {
			comfortable_cows.insert({x, y + 1});
		}
		else if (comfortable_cows.count({x, y + 1})) {
			comfortable_cows.erase({x, y + 1});
		}

		if (is_comfortable(x, y - 1) && cows.count({x, y - 1})) {
			comfortable_cows.insert({x, y - 1});
		}
		else if (comfortable_cows.count({x, y - 1})) {
			comfortable_cows.erase({x, y - 1});
		}

		cout << sz(comfortable_cows) << nl;
	}

	return 0;
}