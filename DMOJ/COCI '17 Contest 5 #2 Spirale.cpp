#include <bits/stdc++.h>
using namespace std;

void F (vector<vector<int>> &B, int M, int N, int X, int Y, int R) {
    if (X < 1 || X > M || Y < 1 || Y > N) return;
    B[Y][X] = min(R, B[Y][X]); return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    
    vector<array<int, 3>> A(K); for (auto &i : A) for (auto &j : i) cin >> j;
    vector<vector<int>> B(N + 1, vector<int> (M + 1, INT_MAX));

    for (array<int, 3> &i : A) {
        int X = i[1], Y = i[0], T = i[2], R = 1;
        B[Y][X] = min(R, B[Y][X]); R++;

        for (int j = 1; j <= max(N, M); j++) {
            Y--; if (T == 0) {
                for (int k = X; k <= i[1] + j; k++) F(B, M, N, k, Y, R), R++; X = i[1] + j;
                for (int k = Y + 1; k <= i[0] + j; k++) F(B, M, N, X, k, R), R++; Y = i[0] + j;
                for (int k = X - 1; k >= i[1] - j; k--) F(B, M, N, k, Y, R), R++; X = i[1] - j;
                for (int k = Y - 1; k >= i[0] - j; k--) F(B, M, N, X, k, R), R++; Y = i[0] - j;
            }
            else {
                for (int k = X; k >= i[1] - j; k--) F(B, M, N, k, Y, R), R++; X = i[1] - j;
                for (int k = Y + 1; k <= i[0] + j; k++) F(B, M, N, X, k, R), R++; Y = i[0] + j;
                for (int k = X + 1; k <= i[1] + j; k++) F(B, M, N, k, Y, R), R++; X = i[1] + j;
                for (int k = Y - 1; k >= i[0] - j; k--) F(B, M, N, X, k, R), R++; Y = i[0] - j;
            }
        }
    }

    for (int i = 1; i <= N; i++) { for (int j = 1; j <= M; j++) { cout << B[i][j] << " "; } cout << "\n"; }
    return 0;
}