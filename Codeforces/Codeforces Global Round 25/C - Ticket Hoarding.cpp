#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, M, K; cin >> N >> M >> K;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    sort(begin(A), end(A));
    long long R1 = 0, R2 = K * K, R3 = 0, R4 = 0;

    for (auto &i : A) {
        if (K - R4 >= M) R1 += i * M, R3 += (M * M), R4 += M;
        else R1 += i * (K - R4), R3 += (K - R4) * (K - R4), R4 += (K - R4);

        if (R4 == K) break;
    }

    cout << R1 + ((R2 - R3) / 2) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}