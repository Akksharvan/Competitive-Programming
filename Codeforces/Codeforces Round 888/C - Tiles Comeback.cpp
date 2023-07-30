#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for (int &i : A) cin >> i;

    int L1 = 0, L2 = -1;
    int R1 = 0, R2 = -1;

    for (int i = 0; i < N; i++) {
        if (A[i] == A[0]) L1++;
        if (L1 == K) { L2 = i; break; }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == A[N - 1]) R1++;
        if (R1 == K) { R2 = i; break; }
    }

    if (L2 == -1 || R2 == -1) {
        cout << "NO" << "\n";
        return;
    }

    if (A[0] == A[N - 1]) {
        cout << "YES" << "\n";
        return;
    }

    if (L2 < R2) {
        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T; cin >> T;
    while (T--) solve();

    return 0;
}