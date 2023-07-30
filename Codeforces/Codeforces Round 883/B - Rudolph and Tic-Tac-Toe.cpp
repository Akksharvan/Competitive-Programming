#include <bits/stdc++.h>
using namespace std;

void solve() {
	array<array<char, 3>, 3> A;
	set<char> B; B.insert('+'); B.insert('O'); B.insert('X');

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}

	for (const char &c : B) {
		for (int i = 0; i < 3; i++) {
			if (A[i][0] == c && A[i][1] == c && A[i][2] == c) {
				cout << c << "\n";
				return;
			}
		}

		for (int j = 0; j < 3; j++) {
			if (A[0][j] == c && A[1][j] == c && A[2][j] == c) {
				cout << c << "\n";
				return;
			}
		}

		if (A[0][0] == c && A[1][1] == c && A[2][2] == c) {
			cout << c << "\n";
			return;
		}

		if (A[2][0] == c && A[1][1] == c && A[0][2] == c) {
			cout << c << "\n";
			return;
		}
	}

	cout << "DRAW" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}