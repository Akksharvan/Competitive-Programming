#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	array<int, 2> B{};

	for (int i = 0; i < N; i++) {
		int X; cin >> X;
		if ((X % 2) == 0) B[0]++;
		else B[1]++;
	}

	if ((B[1] % 4) == 0) { cout << "Alice" << "\n"; return; }
	if ((B[1] % 4) == 1) { cout << ((B[0] % 2) ? "Alice" : "Bob") << "\n"; return; }
	if ((B[1] % 4) == 2) { cout << "Bob" << "\n"; return; }
	if ((B[1] % 4) == 3) { cout << "Alice" << "\n"; return; }

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}