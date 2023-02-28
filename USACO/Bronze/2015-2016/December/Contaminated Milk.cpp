#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M, D, S;
	cin >> N >> M >> D >> S;

	vector<array<int, 3>> A(D); for (array<int, 3> &a : A) cin >> a[0] >> a[1] >> a[2];
	vector<array<int, 2>> B(S); for (array<int, 2> &b : B) cin >> b[0] >> b[1];

	vector<int> C(M + 1);
	for (array<int, 2> &b : B) {
		for (array<int, 3> &a : A) {
			if (a[0] == b[0] && a[2] < b[1]) C[a[1]]++;
		}
	}

	vector<bool> E(N + 1);
	for (int i = 1; i <= M; i++) {
		if (C[i] < S) continue;
		for (array<int, 3> &a : A) {
			if (a[1] == i) E[a[0]] = 1;
		}
	}

	int res = 0; for (bool e : E) if (e) res++;
	cout << res << "\n";

	return 0;
}