#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> rook_locations(m);
		for (int i = 0; i < m; i++) {
			cin >> rook_locations[i].first >> rook_locations[i].second;
			rook_locations[i].first--, rook_locations[i].second--;
		}

		bool possible = false;

		for (int i = 0; i < m; i++) {
			set<int> impossible_x, impossible_y;
			for (int j = 0; j < m; j++) {
				if (j != i) {
					impossible_x.insert(rook_locations[j].first);
					impossible_y.insert(rook_locations[j].second);
				}
			}

			for (int x = 0; x < n; x++) {
				if (x == rook_locations[i].first) {
					continue;
				}
				else if (!impossible_x.count(x)) {
					possible = true;
					break;
				}
			}

			for (int y = 0; y < n; y++) {
				if (y == rook_locations[i].second) {
					continue;
				}
				else if (!impossible_y.count(y)) {
					possible = true;
					break;
				}
			}

			if (possible) {
				break;
			}
		}

		if (possible) {
			cout << "YES" << nl;
		}
		else {
			cout << "NO" << nl;
		}
	}

	return 0;
}