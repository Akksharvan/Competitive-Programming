#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;

	int S = A[0];
	for (int i = 1; i < N; i++) {
		S &= A[i];
	}

	if (S > 0) {
		cout << 1 << "\n";
		return;
	}

	int K = 0; S = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (S == INT_MAX) K++;
		S &= A[i];
		if (!S) S = INT_MAX;
	}

	if (S && S != INT_MAX) K--;
	cout << K << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}