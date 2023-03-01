#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, P = 1, E = 0, O = 0, G = 0; cin >> N;

	for (int i = 0; i < N; i++) {
		int b; cin >> b;

		if (b % 2 == 0) E++;
		else O++;
	}

	while (true) {
		if (P) {
			P = 0; if (E >= 1) { G++; E--; }
			else if (O >= 2) { G++; O -= 2; }
			else break;
		}
		else {
			P = 1; if (O >= 1) { G++; O--; }
			else break;
		}
	}

	if (O % 2 == 1) G--;
	cout << G << "\n";

	return 0;
}