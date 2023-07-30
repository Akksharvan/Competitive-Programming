#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &a : A) cin >> a;
	vector<int> B(N); for (int &b : B) cin >> b;

	vector<int> C(2 * N + 1);
	vector<int> D(2 * N + 1);

	int ret = 1;
	for (int i = 0; i < N - 1; i++) {
		if (A[i + 1] == A[i]) ret++;
		else { C[A[i]] = max(C[A[i]], ret); ret = 1; }
	}

	C[A[N - 1]] = max(C[A[N - 1]], ret); ret = 1;

	for (int i = 0; i < N - 1; i++) {
		if (B[i + 1] == B[i]) ret++;
		else { D[B[i]] = max(D[B[i]], ret); ret = 1; }
	}

	D[B[N - 1]] = max(D[B[N - 1]], ret);

	int res = INT_MIN;
	for (int i = 1; i <= 2 * N; i++) res = max(res, C[i] + D[i]);

	cout << res << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}