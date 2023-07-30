#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n - 1); for (int &x : a) cin >> x;
	vector<int> b(n); for (int i = 0; i < n - 2; i++) b[i + 1] = min(a[i], a[i + 1]);
	
	b[0] = a[0]; b[n - 1] = a[n - 2];
	for (int &x : b) cout << x << " ";
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}