#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K; cin >> N >> K; int res = INT_MIN;
	vector<int> A(N); for (int &a : A) cin >> a;

	for (int &a : A) {
		int ret = 0;
		for (int &b : A) {
			if (a <= b && b - a <= K) ret++;
		}
		
		res = max(res, ret);
	}

	cout << res << "\n";
	return 0;
}