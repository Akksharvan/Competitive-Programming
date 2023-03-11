#include <bits/stdc++.h>
using namespace std;

array<array<bool, (int) 1e5 + 1>, (int) 1e2 + 1> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; vector<int> res; cin >> n; dp[0][0] = 1;
	vector<int> x(n); for (int &i : x) cin >> i;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= (int) 1e5; j++) {
			int ret = j - x[i - 1]; dp[i][j] = dp[i - 1][j];
			if (ret >= 0 && dp[i - 1][ret]) dp[i][j] = 1;
		}
	}

	for (int j = 1; j <= (int) 1e5; j++) if (dp[n][j]) res.push_back(j);
	cout << (int) res.size() << "\n";
	
	for (int &ret : res) cout << ret << " ";
	cout << "\n";

	return 0;
}