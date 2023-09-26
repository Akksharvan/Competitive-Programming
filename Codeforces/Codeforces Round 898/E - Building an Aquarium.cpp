#include <bits/stdc++.h>
using namespace std;

bool F (vector<long long> &A, long long N, long long X, long long M) {
    long long R = 0; for (int i = 0; i < N; i++) R += max(0LL, M - A[i]);
    return (X >= R);
}

void solve() {
    long long N, X; cin >> N >> X;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    long long L = 1, H = 2e9;
    while (L < H) {
        long long M = L + (H - L + 1) / 2;
        if (F(A, N, X, M)) L = M;
        else H = M - 1;
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