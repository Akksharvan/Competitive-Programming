#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, D, H;
	cin >> N >> D >> H;

	long long R = N * H * H;
	long long O = 0;

	vector<long long> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	for (int i = 1; i < N; i++) {
		if (A[i] - A[i - 1] >= H) continue;
		O += ((H - (A[i] - A[i - 1])) * (H - (A[i] - A[i - 1])));
	}

	cout << setprecision(20) << ((double) (R - O) / (2 * H)) * D << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long T; cin >> T;
	while (T--) solve();

	return 0;
}