#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (int &a : A) { cin >> a; --a; }
	vector<int> B(N); for (int &b : B) { cin >> b; }

	vector<int> C(N);
	for (int r = 0; r < 3; r++) {
		for (int i = 0; i < N; i++) C[i] = B[A[i]];
		for (int i = 0; i < N; i++) B[i] = C[i];
	}

	for (int &c : C) cout << c << "\n";
	return 0;
}