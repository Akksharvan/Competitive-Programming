#include <bits/stdc++.h>
using namespace std;

bool foo (pair<int, int> &x, pair<int, int> &y) { return x.second < y.second; }

void solve() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int j; cin >> j;
		a[i] = { j, i };
	}

	vector<int> b(n);
	for (int &i : b) cin >> i;

	sort(begin(a), end(a));
	sort(begin(b), end(b));

	for (int i = 0; i < n; i++) a[i].first = b[i];
	sort(begin(a), end(a), foo);

	for (pair<int, int> &i : a) cout << i.first << " ";
	cout << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}