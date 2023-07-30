#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N; vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	int R = INT_MAX;
	for (int i = 1; i < N; i++) R = min(R, A[i] - A[i - 1] + 1);

	if (R <= 0) cout << 0 << "\n";
	if (R > 0) cout << (!(R % 2) ? (R / 2) : ((R / 2) + 1)) << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}