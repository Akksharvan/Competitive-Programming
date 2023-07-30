#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N; cin >> N;
	for (long long k = 2; k * k <= (N); k++) {
		long long v = k * k * k;

		while ((v - 1) <= N * (k - 1)) {
			if ((v - 1) == N * (k - 1)) {
				cout << "YES" << "\n";
				return;
			}

			v *= k;
		}
	}

	cout << "NO" << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long T; cin >> T;
	while (T--) solve();

	return 0;
}