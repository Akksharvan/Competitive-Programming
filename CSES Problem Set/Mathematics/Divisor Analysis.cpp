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
 
	long long N; cin >> N; vector<pair<long long, long long>> A(N);
	for (pair<long long, long long> &i : A) cin >> i.first >> i.second;
 
	long long R1 = 1, R5 = 1; for (pair<long long, long long> &i : A) R1 *= (i.second + 1), R1 %= MOD, R5 *= (i.second + 1), R5 %= (2 * (MOD - 1));
	long long R2 = 1; for (pair<long long, long long> &i : A) R2 *= ((BP(i.first, i.second + 1, MOD) - 1) * BP(i.first - 1, MOD - 2, MOD)) % MOD, R2 %= MOD;
 
	long long R3 = 1, R4 = 1; bool B = 1; for (pair<long long, long long> &i : A) R3 *= BP(i.first, i.second, MOD), R3 %= MOD, R4 *= BP(i.first, (i.second / 2), MOD), R4 %= MOD, B = ((i.second & 1) ? 0 : B);
	if (B) R3 = BP(R3, ((R5 - 1) % (MOD - 1) / 2) % (MOD - 1), MOD) * R4, R3 %= MOD; else R3 = BP(R3, (R5 / 2) % (MOD - 1), MOD), R3 %= MOD;
 
	cout << R1 << " " << R2 << " " << R3 << "\n";
	return 0;
}