#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, K; cin >> N >> K;
    if (N == 1) { cout << K << "\n"; return; }

    vector<int> R(N); int A = 0;
    for (int i = 0; i < 32; i++) {
        if (A + (1 << i) > K) break;
        else A += (1 << i);
    }

    R[0] = A; R[1] = K - A;
    for (auto &i : R) cout << i << " ";

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}