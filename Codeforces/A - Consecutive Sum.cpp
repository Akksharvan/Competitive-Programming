#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> n_array(n);
		for (int i = 0; i < n; i++) {
			cin >> n_array[i];
		}

		vector<int> k_array(k);
		for (int i = 0; i < k; i++) {
			for (int j = i; j < n; j += k) {
				k_array[i] = max(k_array[i], n_array[j]);
			}
		}

		long long int score = 0;
		for (const int& k_value : k_array) {
			score += k_value;
		}

		cout << score << nl;
	}
	return 0;
}