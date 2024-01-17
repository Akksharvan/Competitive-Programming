#include <bits/stdc++.h>
using namespace std;
    
void solve() {
    long long N, K, X;
    cin >> N >> K >> X;

    if (((N * (N + 1)) / 2) - (((N - K) * ((N - K) + 1)) / 2) < X) cout << "NO" << "\n";
    else if ((K * (K + 1)) / 2 > X) cout << "NO" << "\n";
    else cout << "YES" << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}