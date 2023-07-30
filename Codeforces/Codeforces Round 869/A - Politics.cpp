#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<string> a(n); for (string &s : a) cin >> s;

	vector<bool> b(n, 1); 
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < n; j++) {
			if (a[j][i] != a[0][i]) b[j] = 0;
		}
	}

	int res = accumulate(begin(b), end(b), 0);
	cout << res << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}