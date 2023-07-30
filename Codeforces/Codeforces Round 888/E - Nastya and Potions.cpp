#include <bits/stdc++.h>
using namespace std;

void DFS(long long N, vector<vector<long long>> &A, vector<long long> &C, vector<long long> &V) {
    if (A[N].empty()) return;

    for (long long &L : A[N]) {
        if (V[L]) continue;
        V[L] = 1; DFS(L, A, C, V);
    }

    long long X = 0; for (long long &L : A[N]) X += C[L];
    C[N] = min(C[N], X);
}

void solve() {
    long long N, K; cin >> N >> K;
    vector<long long> C(N + 1), V(N + 1);
    vector<vector<long long>> A(N + 1);

    for (long long i = 1; i <= N; i++) cin >> C[i];
    for (long long i = 0; i < K; i++) { long long X; cin >> X; C[X] = 0; }

    for (long long i = 1; i <= N; i++) {
        long long M; cin >> M;
        for (long long j = 0; j < M; j++) { long long X; cin >> X; A[i].push_back(X); }
    }

    for (long long i = 1; i <= N; i++) {
        if (V[i]) continue;
        V[i] = 1; DFS(i, A, C, V);
    }

    for (long long i = 1; i <= N; i++) cout << C[i] << " ";
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}