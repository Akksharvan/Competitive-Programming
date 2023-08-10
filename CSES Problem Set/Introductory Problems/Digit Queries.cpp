#include <bits/stdc++.h>
using namespace std;

long long F (long long x, long long y) { long long p = 1; while (y--) { p *= x; } return p; }
long long G (long long x, long long y) {
	if (y == 0) return (x % 10);
	else {
		vector<long long> r;
		while (x) { r.push_back(x % 10); x /= 10; }

		reverse(begin(r), end(r));
		return r[y - 1];
	}
}

void solve() {
	long long K; cin >> K;
	long long D = 1, S = 9;

	if (K <= 9) { cout << K << "\n"; return; }

	while (K > S) { D++; S += (D * (9 * F(10, D - 1))); }
	S -= (D * (9 * F(10, D - 1))); K -= S;

	long long A = F(10, D - 1) - 1 + (((K - 1) / D) + 1);
	long long R = (K % D);

	cout << G(A, R) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) solve();

	return 0;
}