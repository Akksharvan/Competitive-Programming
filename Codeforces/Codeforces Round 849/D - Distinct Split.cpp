#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<char> A(N); for (char &a : A) cin >> a;

	map<char, int> B; B[A[0]]++;
	map<char, int> C; for (int i = 1; i < N; i++) C[A[i]]++;

	int R = (int) size(B) + (int) size(C);
	for (int i = 1; i < N - 1; i++) {
		B[A[i]]++; C[A[i]]--; if (!C[A[i]]) C.erase(A[i]);
		R = max(R, (int) size(B) + (int) size(C));
	}

	cout << R << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}