#include <bits/stdc++.h>
using namespace std;

const int MOD = 2019;

long long BP (long long A, long long B, long long M) {
    A %= M; long long R = 1;
    while (B > 0) R *= ((B & 1) ? A : 1), R %= M, A *= A, A %= M, B >>= 1;
    
    return R;
}

int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    vector<vector<int>> DP(N, vector<int> (N));

    for (auto &i : DP) for (auto &j : i) cin >> j;
    for (int i = 0; i < N; i++) for (int j = 1; j < N; j++) DP[i][j] += DP[i][j - 1];

    int R = 0; for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int T = 0; for (int k = 0; k < N; k++) {
            int L = (j - (K - abs(i - k))), H = (j + (K - abs(i - k)));
            L = max(0, L), H = min(N - 1, H); if (abs(i - k) > K) continue;

            T += DP[k][H]; if (L > 0) T -= DP[k][L - 1]; 
        }

        R = max(R, T);
    }

    cout << R << "\n";
    return 0;
}