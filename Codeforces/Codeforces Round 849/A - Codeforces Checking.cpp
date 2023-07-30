#include <bits/stdc++.h>
using namespace std;

const string cf = "codeforces";

void solve() {
	string c; cin >> c;
	cout << ((cf.find(c) != string::npos) ? "YES" : "NO") << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}