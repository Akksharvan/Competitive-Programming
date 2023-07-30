#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &a : A) cin >> a;

	int res = 0;
	for (int &a : A) res += a;

	string B;
	for (int &a : A) B += ((a == 1) ? "1" : "-1");

	if (B.find("-1-1") != string::npos) cout << res + 4 << "\n";
	else if (B.find("-1") != string::npos) cout << res << "\n";
	else cout << res - 4 << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}