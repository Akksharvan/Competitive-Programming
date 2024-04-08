#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; vector<vector<int>> A(N, vector<int> (N));
    for (auto &i : A) for (auto &j : i) cin >> j;

    map<int, array<int, 4>> B;
    array<int, 4> C{};

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (A[i][j] == 0) continue;

        if (B.count(A[i][j])) C = B[A[i][j]];
        else C = {i, i, j, j};

        C[0] = min(C[0], i); C[1] = max(C[1], i);
        C[2] = min(C[2], j); C[3] = max(C[3], j);

        B[A[i][j]] = C;
    }

    vector<vector<int>> DP(N + 1, vector<int> (N + 1));
    for (auto &[i, j] : B) DP[j[0]][j[2]]++, DP[j[1] + 1][j[3] + 1]++, DP[j[0]][j[3] + 1]--, DP[j[1] + 1][j[2]]--;

    for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) {
        if (i > 0) DP[i][j] += DP[i - 1][j];
        if (j > 0) DP[i][j] += DP[i][j - 1];
        if (i && j) DP[i][j] -= DP[i - 1][j - 1];
    }

    vector<bool> D(N * N + 1, 1); D[0] = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (DP[i][j] > 1) D[A[i][j]] = 0;

    auto F = [&N] (vector<vector<int>> &A) {
        set<int> S; for (auto &i : A) for (auto &j : i) S.insert(j);
        if (size(S) == 2) return 1; return 0;
    };

    int R = accumulate(begin(D), end(D), 0);
    R -= F(A); cout << R << "\n"; return 0;
}