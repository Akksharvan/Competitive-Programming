#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N; cin >> N;
	vector<int> A(N), B(2 * N);
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long C = 0;
	long long R = 0;

	B[C] = 1;

	for (int j = 0; j < N; j++) {
		for (long long i = 0; (i * i) < (2 * N); i++) {
			if (((C ^ A[j]) ^ (i * i)) >= (2 * N)) continue;
			R += B[((C ^ A[j]) ^ (i * i))];
		}

		C ^= A[j];
		B[C]++;
	}

	cout << (((N * (N + 1)) / 2) - R) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}