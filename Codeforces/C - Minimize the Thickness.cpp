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

		vector<int> integers(n + 1), prefix_sum(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> integers[i];
		}

		for (int i = 1; i <= n; i++) {
			prefix_sum[i] = prefix_sum[i - 1] + integers[i];
		}

		set<int> possible_target_sums;
		int minimum_thickness = n;

		for (int i = 1; i <= n; i++) {
			if (prefix_sum[n] % i == 0) {
				possible_target_sums.insert(prefix_sum[n] / i);
			}
		}

		for (const int& target_sum : possible_target_sums) {
			bool possible = true;
			int start = 0, end = 0, thickness = 0;

			while (start < n) {
				while (end < n && prefix_sum[end] - prefix_sum[start] < target_sum) {
					end++;
				}

				if (prefix_sum[end] - prefix_sum[start] == target_sum) {
					thickness = max(thickness, end - start);
					start = end;
				}
				else {
					possible = false;
					break;
				}
			}

			if (possible) {
				minimum_thickness = min(minimum_thickness, thickness);
			}
		}

		cout << minimum_thickness << nl;
	}

	return 0;
}