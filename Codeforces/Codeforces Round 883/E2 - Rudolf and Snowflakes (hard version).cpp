#include <bits/stdc++.h>
using namespace std;

bool F (__int128 N, __int128 K, __int128 E) {
    __int128 V = 1;

    for (int i = 0; i < E; i++) {
        V *= K;
        if ((V - 1) > (N * (K - 1))) return 0;
    }

    return ((V - 1) <= (N * (K - 1)));
}

void solve() {
    long long N; cin >> N;
    for (__int128 v = 3; v <= 60; v++) {
        __int128 L = 1, H = 1e9;
        while (L < H) {
            __int128 M = L + (H - L + 1) / 2;
            if (F(N, M, v)) L = M;
            else H = M - 1;
        }

        if (L == 1) continue;

        __int128 V = 1; for (int i = 0; i < v; i++) V *= L;
        if ((V - 1) / (L - 1) != (__int128) N) continue;

        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T; cin >> T;
    while (T--) solve();

    return 0;
}