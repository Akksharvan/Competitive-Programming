#include <bits/stdc++.h>
using namespace std;

void solve() {
	int X, K; cin >> X >> K;
	vector<int> A; int R = X + 1, P = 0;

	while (P != X && R--) {
		while (!(R % K)) R--;
		while (P < X && P + R <= X) { P += R; A.push_back(R); }
	}
	
	cout << (int) A.size() << "\n";
	for (int &a : A) cout << a << " ";

	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}