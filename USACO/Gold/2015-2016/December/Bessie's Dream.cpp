#include <bits/stdc++.h>
using namespace std;

struct STATE {
    int X, Y, D; bool S1, S2;
    STATE(int X, int Y, int D, bool S1, bool S2) : X(X), Y(Y), D(D), S1(S1), S2(S2) {}
};

int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> A(N);

    array<int, 4> DX = {-1, 0, 1, 0};
    array<int, 4> DY = {0, -1, 0, 1};

    set<int> BX; BX.insert(-1); BX.insert(N);
    set<int> BY; BY.insert(-1); BY.insert(M);

    for (auto &i : A) i.resize(M);
    for (auto &i : A) for (auto &j : i) cin >> j;

    STATE S(0, 0, 0, 0, 0);
    queue<tuple<STATE, int>> Q;

    vector<vector<array<array<array<bool, 2>, 2>, 4>>> V(N);
    for (auto &i : V) i.resize(M);

    Q.emplace(S, 0);
    V[S.X][S.Y][S.D][S.S1][S.S2] = 1;

    while (!Q.empty()) {
        auto [S, R] = Q.front();
        Q.pop(); if (S.X == N - 1 && S.Y == M - 1) { cout << R << "\n"; return 0; }

        for (int i = 0; i < 4; i++) {
            if (!S.S1) break;
            if (i != S.D) continue;

            int X = S.X + DX[i], Y = S.Y + DY[i];
            int D = i; bool S1 = S.S1, S2 = S.S2;

            if (BX.count(X)) { S.S1 = 0; break; }
            if (BY.count(Y)) { S.S1 = 0; break; }

            if (A[X][Y] == 0) { S.S1 = 0; break; }
            if (!S.S2 && A[X][Y] == 3) { S.S1 = 0; break; }
        }

        for (int i = 0; i < 4; i++) {
            int X = S.X + DX[i], Y = S.Y + DY[i];
            int D = i; bool S1 = S.S1, S2 = S.S2;

            if (S.S1 && i != S.D) continue;

            if (BX.count(X)) continue;
            if (BY.count(Y)) continue;

            if (A[X][Y] == 0) continue;
            if (A[X][Y] == 3 && !S2) continue;

            if (A[X][Y] == 2) S2 = 1;
            if (A[X][Y] == 4) S2 = 0;

            if (A[X][Y] == 4) S1 = 1;
            if (A[X][Y] != 4) S1 = 0;

            STATE NS(X, Y, D, S1, S2);
            if (V[NS.X][NS.Y][NS.D][NS.S1][NS.S2]) continue;

            Q.emplace(NS, R + 1);
            V[NS.X][NS.Y][NS.D][NS.S1][NS.S2] = 1;
        }
    }

    cout << -1 << "\n";
    return 0;
}