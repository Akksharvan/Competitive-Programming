#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &x : a) cin >> x;
	
	for (int i = 0; i < n; i++) { if (a[i] <= (i + 1)) { cout << "YES" << "\n"; return; } }
	cout << "NO" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}