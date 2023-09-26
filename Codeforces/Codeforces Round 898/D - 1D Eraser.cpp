#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, R = 0; string S;
    cin >> N >> K >> S;

    for (int i = 0; i < N; i++) if (S[i] == 'B') R++, i += (K - 1);
    cout << R << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}