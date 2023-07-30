#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; string S;
	cin >> N >> S;

	stack<int> L, R;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') L.push(i);
		if (S[i] == ')') R.push(i);
	}

	vector<int> A(N);
	while (!L.empty()) {
		if (R.empty()) {
			cout << -1 << "\n";
			return;
		}

		int i = L.top(); L.pop();
		int j = R.top(); R.pop();

		if (i < j) { A[i] = 1; A[j] = 1; }
		if (i > j) { A[i] = 2; A[j] = 2; }
	}

	if (!R.empty()) { cout << -1 << "\n"; return; }
	
	int l = 0, r = 0;
	for (int &a : A) {
		if (a == 1) l = 1;
		if (a == 2) r = 1;
	}

	if (r && !l) fill(begin(A), end(A), 1);

	cout << (l + r) << "\n";
	for (int &a : A) cout << a << " ";
	
	cout << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}