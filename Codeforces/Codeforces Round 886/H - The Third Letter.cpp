#include <bits/stdc++.h>
using namespace std;

void DFS (long long N, vector<vector<long long>> &B, vector<vector<long long>> &C, vector<long long> &D, vector<long long> &V) {
    for (long long i = 0; i < size(B[N]); i++) {
        if (V[B[N][i]]) continue;
        V[B[N][i]] = 1; D[B[N][i]] = D[N] - C[N][i];
        DFS(B[N][i], B, C, D, V);
    }
}

void solve() {
    long long N, M; cin >> N >> M;
    vector<array<long long, 3>> A(M);

    vector<vector<long long>> B(N + 1);
    vector<vector<long long>> C(N + 1);

    for (array<long long, 3> &i : A) {
        cin >> i[0] >> i[1] >> i[2];

        B[i[0]].push_back(i[1]);
        C[i[0]].push_back(i[2]);

        B[i[1]].push_back(i[0]);
        C[i[1]].push_back((-1) * i[2]);
    }

    vector<long long> D(N + 1);
    vector<long long> V(N + 1);

    for (long long i = 1; i <= N; i++) {
        if (V[i]) continue;
        V[i] = 1; D[i] = 0;
        DFS(i, B, C, D, V);
    }

    for (array<long long, 3> &i : A) {
        if (D[i[0]] - i[2] == D[i[1]]) continue;
        cout << "NO" << "\n"; return;
    }

    cout << "YES" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T; cin >> T;
    while (T--) solve();

    return 0;
}