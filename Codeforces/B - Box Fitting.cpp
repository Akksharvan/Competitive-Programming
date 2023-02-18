#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, W;
		cin >> n >> W;

		vector<int> w_array(n);
		for (int i = 0; i < n; i++) {
			cin >> w_array[i];
		}

		sort(w_array.rbegin(), w_array.rend());

		int rows = 1;
		int row_size = 0;
		multiset<int> spaces;

		for (int i = 0; i < n; i++) {
			if (spaces.count(w_array[i])) {
				spaces.erase(spaces.find(w_array[i]));
				cerr << w_array[i] << nl;
			}
			else if (spaces.upper_bound(w_array[i]) != spaces.end()) {
				int difference = *spaces.upper_bound(w_array[i]) - w_array[i];
				spaces.erase(spaces.upper_bound(w_array[i]));
				spaces.insert(difference);
				cerr << w_array[i] << nl;
			}
			else if (row_size + w_array[i] <= W) {
				row_size += w_array[i];
			}
			else {
				spaces.insert(W - row_size);
				row_size = w_array[i];
				rows++;
			}
		}

		cout << rows << nl;
	}

	return 0;
}