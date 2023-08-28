#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
 
	long long N, X; cin >> N >> X;
	vector<long long> A(N); for (long long &i : A) cin >> i;
 
	vector<long long> DP1((1 << N), 1e18);
	vector<long long> DP2((1 << N), 1e18);
 
	for (long long i = 0; i < (1 << N); i++) {
		if (i == 0) DP1[i] = 1;
		if (i == 0) DP2[i] = 0;
 
		for (long long j = 0; j < N; j++) {
			if (i & ((1 << j))) continue;
			long long B = i + (1 << j);
 
			long long C = ((X - DP2[i] >= A[j] ? DP1[i] : DP1[i] + 1));
			long long D = ((X - DP2[i] >= A[j] ? DP2[i] + A[j] : min(DP2[i], A[j])));
 
			if (C == DP1[B]) DP2[B] = min(DP2[B], D);
			else if (C < DP1[B]) DP1[B] = C, DP2[B] = D;
		}
	}
 
	cout << DP1[(1 << N) - 1] << "\n";
	return 0;
}
