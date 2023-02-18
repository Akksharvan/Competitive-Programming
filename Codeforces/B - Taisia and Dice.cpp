#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, s, r;
	cin >> n >> s >> r;

	vector<int> ans(n - 1);
	fill(begin(ans), end(ans), 1);

	int res = n - 1;
	while (res < r) {
		for (int i = 2; i <= 6; i++) {
			for (int j = 0; j < n - 1; j++) {
				ans[j]++; res++;
				if (res == r) break;
			}

			if (res == r) break;
		}
	}

	for (int &i : ans) cout << i << " ";
	cout << (s - r) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}