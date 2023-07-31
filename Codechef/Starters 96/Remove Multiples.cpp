#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long N, M; cin >> N >> M;
	long long A = (N * (N + 1)) / 2;
	
	long long B = 0;
	for (int i = 0; i < M; i++) {
		long long j;
		cin >> j;
		B += j;
	}

	cout << (A - B) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}