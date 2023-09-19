#include <bits/stdc++.h>
using namespace std;

int res = INT_MAX;

array<int, 100> S;
vector<array<int, 4>> A(10);

void foo (string P, int M) {
	if ((int) P.size() < M) {
		foo(P + "0", M); foo(P + "1", M);
		return;
	}

	int ret = 0;
	array<int, 100> C{};

	for (int i = 0; i < M; i++) {
		if (P[i] == '1') {	
			for (int j = A[i][0] - 1; j < A[i][1]; j++) {
				C[j] += A[i][2];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (P[i] == '1') ret += A[i][3];
	}

	for (int i = 0; i < 100; i++) if (S[i] > C[i]) return;
	res = min(res, ret); return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int s, t, c; cin >> s >> t >> c;
		for (int i = s - 1; i < t; i++) S[i] = c;
	}

	A.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3];
	}

	foo("0", M); foo("1", M);
	cout << res << "\n";

	return 0;
}