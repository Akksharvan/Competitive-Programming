#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, K, G;
	cin >> N >> K >> G;

	long long X = K * G; long long C = 0;
	long long R = (G % 2 ? (G / 2) : ((G / 2) - 1));

	if (N * R <= X) {
		X -= (N * R);
		C += (N * R);
	}
	else {
		cout << X << "\n";
		return;
	}

	X %= G;

	if (X != 0) {
		long long D = (R + X); C-= R;
		if ((D % G) >= (R + 1)) C -= (G - (D % G));
		else C += (D % G);
	}

	cout << C << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}