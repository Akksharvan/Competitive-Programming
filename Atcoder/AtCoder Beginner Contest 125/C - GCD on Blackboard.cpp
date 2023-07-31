#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N + 1); for (int i = 1; i <= N; i++) cin >> A[i];
	vector<int> D(N + 2); for (int i = 1; i <= N; ++i) { D[i] = gcd(D[i - 1], A[i]); }
	vector<int> P(N + 2); for (int i = N; i >= 1; --i) { P[i] = gcd(P[i + 1], A[i]); }

	int res = 0;
	for (int i = 1; i <= N; i++) res = max(res, gcd(D[i - 1], P[i + 1]));

	cout << res << "\n";
	return 0;
}