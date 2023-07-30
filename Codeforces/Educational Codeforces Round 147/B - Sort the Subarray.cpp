#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;
	vector<int> B(N); for (int &i : B) cin >> i;

	int L = -1, R = -1;
	for (int i = 0; i < N; i++) {
		if (A[i] != B[i]) {
			L = i;
			break;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		if (A[i] != B[i]) {
			R = i;
			break;
		}
	}

	while ((L - 1) >= 0) {
		if (B[L - 1] <= B[L]) L--;
		else break;
	}

	while ((R + 1) < N) {
		if (B[R + 1] >= B[R]) R++;
		else break;
	}

	cout << (L + 1) << " " << (R + 1) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}