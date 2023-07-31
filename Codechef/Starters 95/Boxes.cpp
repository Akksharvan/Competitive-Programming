#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<long long> A(N); for (long long &i : A) cin >> i;

	sort(rbegin(A), rend(A));
	vector<long long> B; B.push_back(A[0]);

	for (int i = 1; i < N; i++) {
		if (A[i] <= B[size(B) - 1]) B[size(B) - 1] ^= A[i];
		else B.push_back(A[i]);
	}

	cout << size(B) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}