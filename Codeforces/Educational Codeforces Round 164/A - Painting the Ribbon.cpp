#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, M, K; cin >> N >> M >> K;

    if (K >= (N - (N / M) - ((N % M) ? 1 : 0))) cout << "NO" << "\n";
    else cout << "YES" << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}