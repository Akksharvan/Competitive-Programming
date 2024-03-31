#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> A(N, vector<int> (M));

    for (auto &i : A) {
        string S; cin >> S;
        for (int j = 0; j < M; j++) i[j] = (S[j] == '1');
    }

    vector<vector<int>> DP1 = A;
    vector<vector<int>> DP2(N, vector<int> (M));
    vector<vector<int>> DP3(N, vector<int> (M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0) DP1[i][j] += DP1[i - 1][j];
            if (j > 0) DP1[i][j] += DP1[i][j - 1];
            if (i && j) DP1[i][j] -= DP1[i - 1][j - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i && A[i - 1][j] && A[i][j]) DP2[i][j]++;
            if (j && A[i][j - 1] && A[i][j]) DP3[i][j]++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0) DP2[i][j] += DP2[i - 1][j];
            if (j > 0) DP2[i][j] += DP2[i][j - 1];
            if (i && j) DP2[i][j] -= DP2[i - 1][j - 1];

            if (i > 0) DP3[i][j] += DP3[i - 1][j];
            if (j > 0) DP3[i][j] += DP3[i][j - 1];
            if (i && j) DP3[i][j] -= DP3[i - 1][j - 1];
        }
    }

    auto F = [&] (int X1, int Y1, int X2, int Y2) {
        int R1 = DP1[X2][Y2];
        int R2 = DP2[X2][Y2];
        int R3 = DP3[X2][Y2];

        if (X1 > 0) R1 -= DP1[X1 - 1][Y2];
        if (Y1 > 0) R1 -= DP1[X2][Y1 - 1];
        if (X1 && Y1) R1 += DP1[X1 - 1][Y1 - 1];

        R2 -= DP2[X1][Y2];
        R3 -= DP3[X2][Y1];

        if (Y1 > 0) R2 -= DP2[X2][Y1 - 1], R2 += DP2[X1][Y1 - 1];
        if (X1 > 0) R3 -= DP3[X1 - 1][Y2], R3 += DP3[X1 - 1][Y1];

        return (R1 - (R2 + R3));
    };

    while (Q--) {
        int X1, Y1, X2, Y2; cin >> X1 >> Y1 >> X2 >> Y2;
        X1--, Y1--, X2--, Y2--; cout << F(X1, Y1, X2, Y2) << "\n";
    }

    return 0;
}