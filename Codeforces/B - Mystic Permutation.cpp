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

		vector<int> permutation(n), new_permuation(n);
		set<int> digits;

		for (int i = 0; i < n; i++) {
			int digit;
			cin >> digit;

			digits.insert(digit);
			permutation[i] = digit;
		}

		for (int i = 0; i < n; i++) {
			bool e = digits.count(permutation[i]);
			if (e) {
				digits.erase(permutation[i]);
			}

			new_permuation[i] = *digits.lower_bound(1);
			digits.erase(*digits.lower_bound(1));

			if (e) {
				digits.insert(permutation[i]);
			}

			if (i == n - 2) {
				if (digits.count(permutation[i + 1])) {
					new_permuation[i + 1] = new_permuation[i];
					new_permuation[i] = permutation[i + 1];
					break;
				}
			}
		}

		if (n == 1) {
			cout << -1 << nl;
			continue;
		}

		for (const int& i : new_permuation) {
			cout << i << spc;
		}
		cout << nl;
	}

	return 0;
}