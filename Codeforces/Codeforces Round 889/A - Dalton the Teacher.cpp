#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, R = 0; cin >> N;
    for (int i = 1; i <= N; i++) {
        int X; cin >> X;
        if (i == X) R++;
    }

    cout << ((R % 2) ? ((R + 1) / 2) : (R / 2)) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}