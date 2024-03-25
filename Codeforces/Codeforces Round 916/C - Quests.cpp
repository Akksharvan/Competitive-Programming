#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, K; cin >> N >> K;

    vector<long long> A(N); for (auto &i : A) cin >> i;
    vector<long long> B(N); for (auto &i : B) cin >> i;

    long long R1 = 0, R2 = 0, R3 = 0;
    for (int i = 0; i < min(N, K); i++) R2 += A[i], R3 = max(R3, B[i]), R1 = max(R1, R2 + (R3 * (K - (i + 1))));

    cout << R1 << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}