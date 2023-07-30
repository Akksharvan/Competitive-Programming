#include <bits/stdc++.h>
using namespace std;

int choi (char c) { return ((int) (c - '0')); }
char iohc (int i) { return ((char) (i + '0')); }

void solve() {
	string S; int M; cin >> S >> M;
	string L, R; cin >> L >> R;

	int P = -1;
	for (int i = 0; i < M; i++) {
		int V = -1;

		for (int j = choi(L[i]); j <= choi(R[i]); j++) {
			if (S.find(iohc(j), P + 1) == string::npos) { cout << "YES" << "\n"; return; }
			else V = max(V, (int) S.find(iohc(j), P + 1));
		}

		P = V;
	}

	cout << "NO" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}