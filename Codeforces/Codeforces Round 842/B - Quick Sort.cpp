#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, R = INT_MAX, K;
    cin >> N >> K;

    vector<bool> A(N + 1); A[0] = 1;
    for (int i = 0; i < N; i++) {
        int X; cin >> X; A[X] = 1;
        if (!A[X - 1]) R = min(R, X);
    }

    if (R == INT_MAX) cout << 0 << "\n";
    else cout << (((N - R + 1) % K) ? (((N - R + 1) / K) + 1) : ((N - R + 1) / K)) << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}