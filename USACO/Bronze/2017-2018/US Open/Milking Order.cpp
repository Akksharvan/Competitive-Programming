#include <bits/stdc++.h>
using namespace std;

bool F (vector<int> &A, map<int, int> &B, vector<int> &C, int N, int M) {
    int I = 1; for (int i = 0; i < M; i++) {
        if (B.count(A[i]) && B[A[i]] < I) return 0;
        else if (B.count(A[i])) { I = B[A[i]]; continue; }

        while (I <= N && C[I]) I++;
        if (I > N) return 0; C[I] = A[i];
    }

    return 1;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<int> A(M); for (auto &i : A) cin >> i;

    vector<pair<int, int>> B(K);
    for (auto &i : B) cin >> i.first >> i.second;

    for (auto &i : B) {
        if (i.first != 1) continue;
        cout << i.second << "\n"; return 0;
    }

    vector<int> C(N + 1); for (auto &i : B) C[i.second] = i.first;
    map<int, int> D; for (auto &i : B) D[i.first] = i.second;

    for (int i = 1; i <= N; i++) {
        if (C[i]) continue; vector<int> E = C; map<int, int> G = D; G[1] = i; E[i] = 1; 
        if (F(A, G, E, N, M)) { cout << i << "\n"; return 0; }
    }

    return 0;
}