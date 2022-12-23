#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	int n;
	cin >> n;

	multiset<int> tower_heights;
	for (int i = 0; i < n; i++) {
		int cube;
		cin >> cube;

		if (tower_heights.upper_bound(cube) == tower_heights.end()) {
			tower_heights.insert(cube);
		}
		else {
			tower_heights.erase(tower_heights.upper_bound(cube));
			tower_heights.insert(cube);
		}
	}

	cout << sz(tower_heights) << nl;
	return 0;
}