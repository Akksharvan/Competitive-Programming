#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int &i : a) cin >> i;

	if (n == 1) { cout << 1 << "\n"; return; }

	int r = 1;
	for (int i = 1; i < n; i++) if (a[i] > a[r]) r = i;
	if (r != n - 1) r--;

	int l = r;
	while ((l - 1) > 0) {
		if (a[l - 1] > a[0]) l--;
		else break;
	}

	for (int i = r + 1; i < n; i++) cout << a[i] << " ";
	for (int i = r; i >= l; i--) cout << a[i] << " ";
	for (int i = 0; i < l; i++) cout << a[i] << " ";

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