#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S;
	cin >> S;

	if ((int) S.size() < 3) { cout << -1 << "\n"; return; }
	if (find(begin(S) + 1, end(S) - 1, 'O') == end(S) - 1) { cout << -1 << "\n"; return; }

	int res = (int) S.size() - 1;
	if (S.find("MOO") != string::npos) res -= 2;
	else if (S.find("MOM") != string::npos) res--;
	else if (S.find("OOO") != string::npos) res--;

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}