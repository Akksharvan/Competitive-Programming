#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	if (n == 3) cout << "NO" << "\n";
	else if (!(n % 2)) {
		cout << "YES" << "\n";
		for (int i = 1; i <= n; i++) cout << ((i % 2) ? 1 : -1) << " ";
		cout << "\n";
	}
	else {
		cout << "YES" << "\n";
		int ret = n / 2;
		for (int i = 0; i < ret; i++) cout << 1 - ret << " " << ret << " ";
		cout << 1 - ret << "\n";
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) solve();

	return 0;
}