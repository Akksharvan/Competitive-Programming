#include <bits/stdc++.h>
using namespace std;

int H (vector<bool> &A) {
    int R = 0;
    for (int i = 0; i < 32; i++) {
        if (!A[i]) continue;
        R += (1 << i);
    }

    return R;
}

bool G (int L, int R, int K, vector<vector<int>> &DP) {
    vector<bool> A(32);
    for (int i = 0; i < 32; i++) {
        if (DP[R][i] - DP[L - 1][i] != R - (L - 1)) continue;
        else A[i] = 1;
    }

    return (H(A) >= K);
}

int F (int L, int H, int K, int A, vector<vector<int>> &DP) {
    while (A < H) {
        int M = A + (H - A + 1) / 2;
        if (G(L, M, K, DP)) A = M;
        else H = M - 1;
    }

    return A;
}
    
void solve() {
    int N; cin >> N;
    vector<int> A(N + 1); for (int i = 1; i <= N; i++) cin >> A[i];

    vector<vector<int>> DP(N + 1, vector<int> (32));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 32; j++) {
            DP[i][j] += DP[i - 1][j];
            if ((A[i] & (1 << j))) DP[i][j] += 1;
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int L, K; cin >> L >> K;
        cout << ((F(L, N, K, L - 1, DP) == L - 1) ? -1 : F(L, N, K, L - 1, DP)) << " ";
    }

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