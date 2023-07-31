#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, M, H; cin >> N >> M >> H;
	vector<long long> A(N); for (long long &i : A) cin >> i;
	vector<long long> B(M); for (long long &i : B) cin >> i;

	sort(rbegin(A), rend(A));
	sort(rbegin(B), rend(B));

	long long R = 0; for (int i = 0; i < min(N, M); i++) R += min(A[i], B[i] * H);
	cout << R << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}