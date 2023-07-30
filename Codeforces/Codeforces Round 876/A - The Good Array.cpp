#include <bits/stdc++.h>
using namespace std;

int F (int N, int K) { return (1 + ((N - 1) / K + (((N - 1) % K) ? 1 : 0))); }

void solve() {
	int N, K; cin >> N >> K;
	cout << F(N, K) << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}