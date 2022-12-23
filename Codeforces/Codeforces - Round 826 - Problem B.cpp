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
		int n;
		cin >> n;

		if (n == 3) {
			cout << -1 << nl;
		}
		else if (n == 2) {
			cout << 2 << spc << 1 << nl;
		}
		else {
			vector<int> funny_permutation;
			for (int i = n; i > 0; i--) {
				funny_permutation.push_back(i);
			}

			for (int i = n/2; i < n - 1; i += 2) {
				funny_permutation[i] = funny_permutation[i + 1];
				funny_permutation[i + 1] = funny_permutation[i] + 1;
			}

			if (abs(funny_permutation[n - 1] - funny_permutation[n - 2]) > 1) {
				swap(funny_permutation[n - 2], funny_permutation[n - 3]);
				swap(funny_permutation[n - 1], funny_permutation[n - 3]);
			}

			for (int i = 0; i < n; i++) {
				cout << funny_permutation[i] << spc;
			}

			cout << nl;
		}
	}

	return 0;
}