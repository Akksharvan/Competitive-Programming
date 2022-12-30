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

		vector<int> arr(n), numbers((int) 2e3, -1);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			numbers[arr[i]] = i + 1;
		}

		int max_val = 0;
		for (int i = 1; i <= (int) 1e3; i++) {
			if (numbers[i] == -1) {
				continue;
			}

			for (int j = i; j <= (int) 1e3; j++) {
				if (numbers[j] == -1) {
					continue;
				}

				if (gcd(i, j) == 1) {
					max_val = max(max_val, numbers[i] + numbers[j]);
				}
			}
		}

		if (max_val) {
			cout << max_val << nl;
		}
		else {
			cout << -1 << nl;
		}
	}

	return 0;
}