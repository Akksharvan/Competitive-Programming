#include <bits/stdc++.h>
using namespace std;

long long choi (char c) { return ((long long) (c - '0')); }

void solve() {
	long long N; cin >> N;
	string S; cin >> S;

	vector<long long> A(N);
	for (long long i = 0; i < N; i++) A[i] = choi(S[i]);
	for (long long i = 1; i < N; i++) A[i] += A[i - 1];

	map<long long, long long> B; B[0]++;
	for (long long i = 1; i <= N; i++) B[A[i - 1] - i]++;

	long long R = 0;
	for (const pair<long long, long long> &i : B) {
		if (i.second == 1) continue;
		R += ((i.second) * (i.second - 1)) / 2;
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