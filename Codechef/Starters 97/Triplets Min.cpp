#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, Q;
	cin >> N >> Q;

	vector<long long> A(N);
	for (long long &i : A) cin >> i;

	vector<array<long long, 2>> B(Q);
	for (int i = 0; i < Q; i++) { B[i][1] = i; cin >> B[i][0]; }

	long long R = 0; sort(rbegin(B), rend(B));
	sort(begin(A), end(A)); vector<long long> C(Q);

	for (long long i = 0; i < N - 2; i++) {
		R += (N - (i + 1)) * (N - (i + 2)) / 2;
		while (!B.empty() && B[size(B) - 1][0] <= R) {
			C[B[size(B) - 1][1]] = A[i];
			B.pop_back();
		}
	}

	for (long long &i : C) cout << i << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}