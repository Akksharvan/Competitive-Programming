#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, K; cin >> N >> K;
	vector<long long> A(N); for (auto &i : A) cin >> i;

	sort(begin(A), end(A));
	long long L = A[0], H = A[N - 1] + K;

	auto F = [&A, &K] (long long X) {
		long long R = 0;
		for (auto &i : A) if (i < X) R += (X - i);

		return (K >= R);
	};
	
	while (L < H) {
		long long M = L + (H - L + 1) / 2;
		if (F(M)) L = M;
		else H = M - 1;
	}

	for (auto &i : A) if (i < L) K -= (L - i), i = L;
	for (auto &i : A) if (K > 0 && i == L) i++, K--;

	long long R1 = count(begin(A), end(A), L);
	long long R2 = N - R1;

	long long R3 = (N * L) + R2 - (N - 1);
	cout << R3 << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();
}