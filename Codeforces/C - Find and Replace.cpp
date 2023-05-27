#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<char> a(n); for (char &c : a) cin >> c;

	map<char, int> b; b[a[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (b.count(a[i]) && b[a[i - 1]] == b[a[i]]) {
			cout << "NO" << "\n";
			return;
		}

		b[a[i]] = (1 ^ b[a[i - 1]]);
	}

	cout << "YES" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}