#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (int &i : A) cin >> i;

	vector<int> B(N);
	for (int &i : A) if (i < N) B[i]++;

	vector<int> C(N); C[0] = B[0];
	for (int i = 1; i < N; i++) C[i] = min(C[i - 1], B[i]);

	int D = 0, E = 0; vector<int> F;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < (C[i] - D); j++) F.push_back(i + 1);
		E += ((C[i] - D) * (i + 1)); D += (C[i] - D);
	}

	while (E < N) { F.push_back(0); E++; }
	cout << size(F) << "\n";

	for (int &i : F) cout << i << " ";
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}