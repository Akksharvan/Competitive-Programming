#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, X1 = 0, X2 = 1e9; cin >> N;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    for (int i = 1; i < N; i++) {
        if (A[i - 1] == A[i]) continue;

        if (A[i - 1] <= A[i]) X2 = min(X2, (A[i - 1] + A[i]) / 2);
        else X1 = max(X1, (A[i - 1] + A[i]) / 2 + ((A[i - 1] + A[i]) % 2));
    }

    if (X1 > X2) cout << -1 << "\n";
    else cout << X1 << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}