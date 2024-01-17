#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
 
long long BP (long long A, long long B, long long M) {
    A %= M; long long R = 1;
	while (B > 0) R *= ((B & 1) ? A : 1), R %= M, A *= A, A %= M, B >>= 1;
	
	return R;
}
 
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);
 
	string S; cin >> S; long long N = size(S); vector<long long> A(26); for (char &i : S) A[i - 97]++;
	vector<long long> B(N + 1); B[0] = 1; for (int i = 1; i <= N; i++) B[i] = B[i - 1] * i, B[i] %= MOD;
 
	long long R = B[N]; for (long long &i : A) R *= BP(B[i], MOD - 2, MOD), R %= MOD;
	cout << R << "\n"; return 0;
}