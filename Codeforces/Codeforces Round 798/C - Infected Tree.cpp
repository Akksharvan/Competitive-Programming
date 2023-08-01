#include <bits/stdc++.h>
using namespace std;

void DFS1 (int N, int U, vector<vector<int>> &A, vector<vector<int>> &DP) {
    for (int &L : A[N]) {
        if (L == U) continue;
        DFS1(L, N, A, DP); DP[0][N] += DP[0][L];
    }
}

void DFS2 (int N, int U, vector<vector<int>> &A, vector<vector<int>> &DP) {
    for (int &L : A[N]) {
        if (L == U) continue;
        DFS2(L, N, A, DP);
    }

    vector<int> B, C;
    for (int &L : A[N]) {
        if (L == U) continue;
        B.push_back(DP[0][L]);
        C.push_back(DP[1][L]);
    }

    if (B.empty()) return;
    else if (size(B) == 1) DP[1][N] = B[0] - 1;
    else DP[1][N] = max(C[1] + B[0] - 1, C[0] + B[1] - 1);
}

void solve() {
    int N; cin >> N;
    vector<vector<int>> A(N + 1);
    
    for (int i = 0; i < N - 1; i++) {
        int U, V; cin >> U >> V;
        A[U].push_back(V); A[V].push_back(U);
    }

    vector<vector<int>> DP(2, vector<int> (N + 1));
    fill(begin(DP[0]), end(DP[0]), 1);
    fill(begin(DP[1]), end(DP[1]), 0);

    DFS1(1, 0, A, DP);
    DFS2(1, 0, A, DP);

    cout << DP[1][1] << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}