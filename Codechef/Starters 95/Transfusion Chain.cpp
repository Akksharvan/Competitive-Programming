#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<string> BT(N); for (string &i : BT) cin >> i;

	int A = 0, B = 0, O = 0, AB = 0;
	for (string &i : BT) {
		if (i == "A") A++;
		if (i == "B") B++;
		if (i == "O") O++;
		if (i == "AB") AB++;
	}

	cout << (O + max(A, B) + AB) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}