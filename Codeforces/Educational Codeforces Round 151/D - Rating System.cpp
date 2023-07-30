#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N; cin >> N;
	vector<long long> A(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	vector<long long> DP(N + 1);
	for (int i = 1; i <= N; i++) DP[i] = DP[i - 1] + A[i];

	long long M = DP[N];
	long long R = DP[N];

	multiset<long long> B;
	for (int i = 1; i <= N; i++) B.insert(DP[i]);

	if (DP[N] + max(0 - *begin(B), 0LL) > M) {
		M = DP[N] + (0 - *begin(B));
		R = 0;
	}

	for (int i = 1; i < N; i++) {
		B.erase(B.find(DP[i]));
		if (*begin(B) >= DP[i]) continue;

		if (DP[N] + (DP[i] - *begin(B)) > M) {
			M = DP[N] + (DP[i] - *begin(B));
			R = DP[i];
		}
	}

	cout << R << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}