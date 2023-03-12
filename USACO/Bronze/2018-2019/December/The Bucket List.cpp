#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N; cin >> N; vector<int> A(N), B(N), C(N);
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i];

	int res = 0;
	for (int t = 1; t <= 1000; t++) {
		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] <= t && t <= B[i]) ret += C[i];
			res = max(res, ret);
		}
	}

	cout << res << "\n";
	return 0;
}