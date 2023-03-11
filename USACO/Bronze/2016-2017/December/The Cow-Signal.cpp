#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int M, N, K; cin >> M >> N >> K;
	vector<string> A(M); for (string &a : A) cin >> a;

	for (int i = 0; i < K * M; i++) {
		for (int j = 0; j < K * N; j++) cout << A[i / K][j / K];
		cout << "\n";
	}

	return 0;
}