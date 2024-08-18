#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, M, R = 0;
	cin >> N >> M;

	for (long long i = 1; i <= M; i++) {
		for (long long j = i; j <= N; j += i) {
			if (((j / i) + 1) % i) continue;
			else R++;
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
}