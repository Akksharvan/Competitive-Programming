#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;

    vector<vector<long long>> A(N, vector<long long> (M));
    vector<vector<long long>> DP(M, vector<long long> (N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            DP[j][i] = A[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        sort(begin(DP[i]), end(DP[i]));
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) A[j][i] = DP[i][j];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 1; j < N; j++) DP[i][j] += DP[i][j - 1];
    }

    long long R = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (N - 1); j++) {
            R += ((DP[i][N - 1] - DP[i][j]) - ((N - (j + 1)) * A[j][i]));
        }
    }

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}