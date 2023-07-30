#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

	if (n == 1) cout << 1 << "\n";
	else if (n % 2) cout << -1 << "\n";
	else {
		int e = n, o = n - 1;
		while (e >= 2) {
			cout << o << " " << e << " ";
			e -= 2; o -= 2;
		}

		cout << "\n";
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}