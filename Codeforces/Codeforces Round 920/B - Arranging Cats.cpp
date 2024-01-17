#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, R1 = 0, R2 = 0; cin >> N;
    string S, F; cin >> S >> F;

    for (int i = 0; i < N; i++) {
        if (S[i] == '1' && F[i] == '0') R1++;
        else if (S[i] == '0' && F[i] == '1') R2++;
    }

    cout << max(R1, R2) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}