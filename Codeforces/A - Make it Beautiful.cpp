#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &x : a) cin >> x;
	
	sort(a.begin(), a.end());

	int l = 0, r = n - 1;
	if (a[l] == a[r]) cout << "NO" << "\n";
	else {
		cout << "YES" << "\n";

		for (int i = 0; i < n; i++) {
			if (!(i % 2)) {
				cout << a[r] << " ";
				r--;
			}
			else {
				cout << a[l] << " ";
				l++;
			}
		}

		cout << "\n";
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}