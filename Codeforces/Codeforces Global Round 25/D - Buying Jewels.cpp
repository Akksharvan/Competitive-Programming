#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, K; cin >> N >> K;

    if (K > N || K < N && 2 * K > N + 1) cout << "NO" << "\n";
    else cout << "YES" << "\n" << 2 << "\n" << N - K + 1 << " " << 1 << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}