#include <bits/stdc++.h>
using namespace std;

long long F (long long B, long long K) {
    long long L = 0;
    long long H = 1e9;
    
    while (L < H) {
        long long M = L + (H - L) / 2;
        if (M * (K - 1) >= (B + 1)) H = M;
        else L = M + 1;
    }

    return L;
}

void solve () {
    long long K, X, A; cin >> K >> X >> A;
    long long B = 0; for (int i = 0; i <= X; i++) B += F(B, K);

    if (B <= A) cout << "YES" << "\n";
    else cout << "NO" << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}