#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
array<long long, (int) 1e5 + 1> D;

long long F (long long a, long long b) {
	long long r = 1; 
	while (b) {
		if (b & 1) { r *= a; r %= MOD; }
		a = (a * a) % MOD; b >>= 1;
	}
 
	return (r % MOD);
}

void solve() {
    long long N; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;
    vector<long long> B(2); for (long long &i : A) B[i % 2]++;

    long long res = 0;
    for (long long i = 0; i <= B[0]; i++) {
        res += (D[B[0]] * F(((D[i] * D[B[0] - i]) % MOD), MOD - 2)) % MOD;
        res %= MOD;
    }

    cout << ((B[1]) ? (res % MOD) : ((res - 1) % MOD)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    D[0] = 1; for (long long i = 1; i <= 1e5; i++) { D[i] = (i * D[i - 1]) % MOD; D[i] %= MOD; }
    int T; cin >> T; while (T--) solve();

    return 0;
}