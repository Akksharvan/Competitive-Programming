#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	string s1, s2;
	cin >> s1 >> s2;

	int t1 = 0; int t2 = 0;
	for (int i = 1; i < n; i++) if (s1[i] == s1[i - 1]) t1++;
	for (int i = 1; i < m; i++) if (s2[i] == s2[i - 1]) t2++;

	if (!t1 && !t2) cout << "YES" << "\n";
	else if (t1 && t2) cout << "NO" << "\n";
	else if (s1[n - 1] != s2[m - 1]) {
		if (t1 < 2 && t2 < 2) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	else cout << "NO" << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}