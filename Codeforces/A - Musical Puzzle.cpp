#include <bits/stdc++.h>
using namespace std;

void solve() {
	set<pair<char, char>> m; int n; string s; cin >> n >> s;
	for (int i = 0; i < n - 1; i++) m.insert({s[i], s[i + 1]});

	cout << (int) m.size() << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}