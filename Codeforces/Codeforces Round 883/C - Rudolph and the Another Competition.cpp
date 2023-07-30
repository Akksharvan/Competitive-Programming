#include <bits/stdc++.h>
using namespace std;

bool foo (array<long long, 3> &x , array<long long, 3> &y) {
	if (x[0] == y[0]) {
		if (x[1] == y[1]) {
			return x[2] < y[2];
		}
		
		return x[1] < y[1];
	}

	return x[0] > y[0];
}

void solve() {
	long long N, M, H;
	cin >> N >> M >> H;

	vector<vector<long long>> A(N, vector<long long> (M));
	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < M; j++) {
			cin >> A[i][j];
		}

		sort(begin(A[i]), end(A[i]));
		for (long long j = 1; j < M; j++) {
			A[i][j] += A[i][j - 1];
		}

		while (!A[i].empty() && A[i][size(A[i]) - 1] > H) {
			A[i].pop_back();
		}

		for (long long j = 1; j < M; j++) {
			A[i][j] += A[i][j - 1];
		}
	}

	vector<array<long long, 3>> B(N);
	for (long long i = 0; i < N; i++) {
		B[i][0] = size(A[i]);
		B[i][1] = (!A[i].empty() ? A[i][size(A[i]) - 1] : 0);
		B[i][2] = i;
	}

	long long P; sort(begin(B), end(B), foo);
	for (long long i = 0; i < N; i++) {
		if (B[i][2] == 0) {
			P = (i + 1);
		}
	}

	cout << P << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long T; cin >> T;
	while (T--) solve();

	return 0;
}