#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, R = 0; cin >> N;
	vector<int> A(N), B(N);

	for (auto &i : A) cin >> i;
	for (auto &i : B) cin >> i;

	for (int i = 0; i < N; i++) {
		if (A[i - R] <= B[i]) continue;
		else R++;
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