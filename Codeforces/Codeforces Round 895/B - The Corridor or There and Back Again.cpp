#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    int R = INT_MAX;

    for (int i = 0; i < N; i++) {
        int D, S; cin >> D >> S;
        R = min(R, D + (S / 2) - (S % 2 ? 0 : 1));
    }

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