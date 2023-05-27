#include <bits/stdc++.h>
using namespace std;

void solve() {
	string S; cin >> S;
	int N = (int) S.size();

	for (int i = 0; i < N; i++) {
		if (S[i] == '?') {
			if (i == 0) S[i] = '0';
			else S[i] = S[i - 1];
		}
	}

	cout << S << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}