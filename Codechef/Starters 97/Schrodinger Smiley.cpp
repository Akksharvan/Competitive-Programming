#include <bits/stdc++.h>
using namespace std;

bool foo (string &S, int i, int j) {
	for (int k = i + 1; k < j; k++) {
		if (S[k] != ')') return 0;
	}

	return 1;
}

void solve() {
	int N; cin >> N;
	string S; cin >> S;

	vector<int> A;
	for (int i = 0; i < N; i++) {
		if (S[i] == ':') A.push_back(i);
	}

	if (size(A) <= 1) {
		cout << 0 << "\n";
		return;
	}

	int R = 0;
	for (int i = 0; i < size(A) - 1; i++) {
		if (A[i + 1] == A[i] + 1) continue;
		if (foo(S, A[i], A[i + 1])) R++;
	}

	cout << R << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}