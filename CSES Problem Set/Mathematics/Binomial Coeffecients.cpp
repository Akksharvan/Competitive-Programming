#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
array<long long, (int) 1e6 + 1> F;
 
long long BP (long long A, long long B, long long M) {
    A %= M; long long R = 1;
	while (B > 0) R *= ((B & 1) ? A : 1), R %= M, A *= A, A %= M, B >>= 1;
	
	return R;
}
 
void solve () {
	long long A, B; cin >> A >> B;
	cout << (B ? ((F[A] * BP(F[B] * F[A - B] % MOD, MOD - 2, MOD)) % MOD) : 1) << "\n";
}
 
int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);
 
	F[1] = 1; for (int i = 2; i <= 1e6; i++) F[i] = (F[i - 1] * i), F[i] %= MOD;
	int T; cin >> T; while (T--) solve();
 
	return 0;
}