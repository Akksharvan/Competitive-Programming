#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; int res = INT_MIN;
	vector<pair<int, int>> A(N);
	for (pair<int, int> &a : A) cin >> a.first >> a.second;

	for (pair<int, int> &a : A) {
		vector<bool> T((int) 1e3);
		for (pair<int, int> &b : A) {
			if (a == b) continue;
			for (int t = b.first; t < b.second; t++) T[t] = 1;
		}

		int ret = 0; for (int t = 0; t < (int) 1e3; t++) ret += T[t];
		res = max(res, ret);
	}

	cout << res << "\n";
	return 0;
}