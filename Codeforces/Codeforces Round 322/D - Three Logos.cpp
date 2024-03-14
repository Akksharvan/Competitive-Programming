#include <bits/stdc++.h>
using namespace std;

struct L {
    int X, Y; char C; int S () { return X * Y; }
    bool operator < (L &i) { return S() < i.S(); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<L> A(3); for (auto &i : A) cin >> i.X >> i.Y; A[0].C = 'A'; A[1].C = 'B'; A[2].C = 'C'; sort(begin(A), end(A));
    int N = 0; for (auto &i : A) N += i.S(); if ((int) sqrt(N) * (int) sqrt(N) != N) { cout << -1 << "\n"; return 0; }

    N = (int) sqrt(N); do {
        if ((A[0].X == N || A[0].Y == N) && (A[1].X == N || A[1].Y == N) && (A[2].X == N || A[2].Y == N)) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < min(A[0].X, A[0].Y); i++) for (int j = 0; j < N; j++) C[i][j] = A[0].C;
            for (int i = min(A[0].X, A[0].Y); i < min(A[0].X, A[0].Y) + min(A[1].X, A[1].Y); i++) for (int j = 0; j < N; j++) C[i][j] = A[1].C;
            for (int i = min(A[0].X, A[0].Y) + min(A[1].X, A[1].Y); i < N; i++) for (int j = 0; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].X + A[1].X == N && A[0].Y == A[1].Y && A[2].X == N && A[2].Y == N - A[0].Y) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].X; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[0].C;
            for (int i = A[0].X; i < N; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].Y; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].X + A[1].X == N && A[0].Y == A[1].Y && A[2].Y == N && A[2].X == N - A[0].Y) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].X; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[0].C;
            for (int i = A[0].X; i < N; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].Y; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].Y + A[1].X == N && A[0].X == A[1].Y && A[2].X == N && A[2].Y == N - A[0].X) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].Y; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[0].C;
            for (int i = A[0].Y; i < N; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].X; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].Y + A[1].X == N && A[0].X == A[1].Y && A[2].Y == N && A[2].X == N - A[0].X) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].Y; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[0].C;
            for (int i = A[0].Y; i < N; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].X; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].X + A[1].Y == N && A[0].Y == A[1].X && A[2].X == N && A[2].Y == N - A[0].Y) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].X; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[0].C;
            for (int i = A[0].X; i < N; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].Y; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].X + A[1].Y == N && A[0].Y == A[1].X && A[2].Y == N && A[2].X == N - A[0].Y) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].X; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[0].C;
            for (int i = A[0].X; i < N; i++) for (int j = 0; j < A[0].Y; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].Y; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].Y + A[1].Y == N && A[0].X == A[1].X && A[2].X == N && A[2].Y == N - A[0].X) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].Y; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[0].C;
            for (int i = A[0].Y; i < N; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].X; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }

        if (A[0].Y + A[1].Y == N && A[0].X == A[1].X && A[2].Y == N && A[2].X == N - A[0].X) {
            vector<vector<char>> C(N, vector<char> (N));

            for (int i = 0; i < A[0].Y; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[0].C;
            for (int i = A[0].Y; i < N; i++) for (int j = 0; j < A[0].X; j++) C[i][j] = A[1].C;
            for (int i = 0; i < N; i++) for (int j = A[0].X; j < N; j++) C[i][j] = A[2].C;

            cout << N << "\n"; for (auto &i : C) { for (auto &j : i) cout << j; cout << "\n"; } return 0;
        }
    } while (next_permutation(begin(A), end(A))); 

    cout << -1 << "\n";
    return 0;
}