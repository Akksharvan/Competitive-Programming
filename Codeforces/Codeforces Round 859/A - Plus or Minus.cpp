#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long a, b, c;
	cin >> a >> b >> c;

	if (a + b == c) cout << "+" << "\n";
	else cout << "-" << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}