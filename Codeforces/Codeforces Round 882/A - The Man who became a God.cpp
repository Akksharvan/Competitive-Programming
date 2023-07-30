#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N); for (int &i : A) cin >> i;

	vector<int> B;
	for (int i = 0; i < N - 1; i++) { 
		B.push_back(abs(A[i + 1] - A[i]));
	}

	sort(begin(B), end(B));
	while ((K - 1)) { B.pop_back(); K--; }

	int R = accumulate(begin(B), end(B), 0);
	cout << R << "\n"; return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}