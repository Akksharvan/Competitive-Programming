#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N); for (int &i : A) cin >> i;

	int L = 0, R = N - 1;

	while ((N - 1) - L >= K) L++;
	while (R >= K) R--;

	if (L > R) {
		sort(begin(A), end(A));
		for (int &i : A) cout << i << " ";
		cout << "\n"; return;
	}

	priority_queue<int, vector<int>, greater<int>> B;
	for (int i = 0; i < L; i++) B.push(A[i]);
	for (int i = R + 1; i < N; i++) B.push(A[i]);

	for (int i = 0; i < L; i++) { cout << B.top() << " "; B.pop(); }
	for (int i = L; i <= R; i++) { cout << A[i] << " "; }
	for (int i = R + 1; i < N; i++) { cout << B.top() << " "; B.pop(); }

	cout << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}