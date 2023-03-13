#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N; vector<int> R(N);
	int t = 0; for (int r = 0; r < N; r++) { cin >> R[r]; t += R[r]; }

	int res = INT32_MAX;
	for (int i = 0; i < N; i++) {
		int ret = 0; int l = t;
		for (int j = 0; j < N; j++) { l -= R[(i + j) % N]; ret += l; }
		res = min(res, ret);
	}

	cout << res << endl;
	return 0;
}