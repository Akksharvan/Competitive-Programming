#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;

	vector<int> a(n);
	for (int &x : a) cin >> x;

	priority_queue<int, vector<int>, greater<int>> C;
	for (int i = 0; i < n; i++) {
		C.push(i + 1 + a[i]);
	}

	int res = 0;
	while (!C.empty()) {
		if (C.top() > c) break;
		else { c -= C.top(); C.pop(); res++; }
	}

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}