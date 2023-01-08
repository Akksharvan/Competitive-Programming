#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K, B;
	cin >> N >> K >> B;

	vector<bool> broken(N + 1);
	while (B--) { int b; cin >> b; broken[b] = 1; }
	
	int res = INT_MAX, ret = 0;
	int l = 1, r = l + K - 1;

	for (int i = l; i <= r; i++) if (broken[i]) ret++;
	res = min(res, ret);

	while (r < N) {
		if (broken[l]) ret--;
		if (broken[r + 1]) ret++;

		l++, r++;
		res = min(res, ret);
	}

	cout << res << "\n";
	return 0;
}