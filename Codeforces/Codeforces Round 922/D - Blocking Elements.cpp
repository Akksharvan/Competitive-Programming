#include <bits/stdc++.h>
using namespace std;

bool F (vector<long long> &A, long long N, long long X) {
    vector<long long> DP(N); multiset<long long> C;
    long long T = 0, L = 0, H = 0; while (H < N && T <= X) { DP[H] = A[H]; C.insert(A[H]); T += A[H]; H++; }

    for (int i = H; i < N; i++) {
        while (T > X) { T -= A[L]; C.extract(DP[L - 1]); L++; }
        DP[i] = *begin(C) + A[i]; C.insert(DP[i]); T += A[i];
    }

    T = 0; for (int i = N - 1; i >= 0; i--) { if (T > X) break; if (DP[i] <= X) return 1; T += A[i]; }
    return 0;
}

void solve () {
    long long N; cin >> N; vector<long long> A(N);
    for (auto &i : A) cin >> i;

    long long L = *max_element(begin(A), end(A));
    long long H = 1e14;

    while (L < H) {
        long long M = L + (H - L) / 2;
        if (F(A, N, M)) H = M;
        else L = M + 1;
    }

    cout << L << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}