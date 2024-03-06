#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353; array<long long, (int) 4e6 + 1> F; 
inline void S () { F[0] = 1; for (int i = 1; i <= 4e6; i++) F[i] = (F[i - 1] * i) % MOD; }

long long BP (long long A, long long B, long long M) {
    A %= M; long long R = 1;
    while (B > 0) R *= ((B & 1) ? A : 1), R %= M, A *= A, A %= M, B >>= 1;

    return R;
}

long long G (long long N, long long K) {
    return ((F[N + K - 1] * BP((F[K] * F[N - 1]) % MOD, MOD - 2, MOD)) % MOD);
}

void solve () {
    array<long long, 4> A{};
    for (auto &i : A) cin >> i;

    if (A[0] + A[1] == 0) { cout << (min(A[2], A[3]) ? 0 : 1) << "\n"; return; }
    if (abs(A[0] - A[1]) > 1) { cout << 0 << "\n"; return; }

    if (A[0] > A[1]) cout << ((G(A[0], A[2]) * G(A[1] + 1, A[3])) % MOD) << "\n";
    else if (A[0] < A[1]) cout << ((G(A[0] + 1, A[2]) * G(A[1], A[3])) % MOD) << "\n";
    else cout << (((G(A[0] + 1, A[2]) * G(A[1], A[3])) % MOD) + ((G(A[0], A[2]) * G(A[1] + 1, A[3])) % MOD)) % MOD << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    S(); int T; cin >> T;
    while (T--) solve();

    return 0;
}