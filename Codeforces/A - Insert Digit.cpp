#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; char d; cin >> n >> d;
	vector<char> s(n); for (char &c : s) cin >> c;

	for (vector<char>::iterator it = begin(s); it < end(s); it++) { if ((int) (*it - '0') < (int) (d - '0')) { s.insert(it, d); break; } }
	if ((int) s.size() == n) s.insert(end(s), d);

	for (char &c : s) cout << c;
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}