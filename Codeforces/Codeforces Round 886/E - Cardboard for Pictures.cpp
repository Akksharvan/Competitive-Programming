#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, C; cin >> N >> C;
    __int128 A = 0, B = 0;

    for (int i = 0; i < N; i++) {
        long long X; cin >> X;
        C -= (X * X); A += 4; B += (4 * X);
    }

    __int128 L = 0, H = 1e9;
    while (L < H) {
        __int128 M = L + (H - L + 1) / 2;
        if (((A * M * M) + (B * M)) <= (__int128) C) L = M;
        else H = M - 1;
    }

    cout << (long long) L << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}