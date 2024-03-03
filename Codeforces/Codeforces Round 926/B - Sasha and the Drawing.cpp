#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, K; cin >> N >> K;
    cout << (K == 4 * N - 2 ? (K / 2 + 1) : ((K / 2) + (K % 2))) << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}