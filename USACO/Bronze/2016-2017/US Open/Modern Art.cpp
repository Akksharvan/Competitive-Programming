#include <bits/stdc++.h>
using namespace std;

inline void F (vector<string> &A, map<char, array<int, 4>> &B, int i, int j) {
    if (!B.count(A[i][j])) B[A[i][j]] = {i, i, j, j};

    B[A[i][j]][0] = min(B[A[i][j]][0], i);
    B[A[i][j]][1] = max(B[A[i][j]][1], i);

    B[A[i][j]][2] = min(B[A[i][j]][2], j);
    B[A[i][j]][3] = max(B[A[i][j]][3], j);
}

inline bool G (vector<string> &A, map<char, array<int, 4>> &B, vector<char> &C) {
    int N = size(A); vector<vector<char>> D(N, vector<char>(N, '0'));
    for (auto &c : C) for (int i = B[c][0]; i <= B[c][1]; i++) for (int j = B[c][2]; j <= B[c][3]; j++) D[i][j] = c;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (A[i][j] != D[i][j]) return 0;
    return 1;
}

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; vector<string> A(N);
    for (auto &i : A) cin >> i;

    map<char, array<int, 4>> B;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) F(A, B, i, j);

    B.erase('0'); vector<char> C; set<char> D;
    for (const auto &[i, j] : B) C.push_back(i);
    
    do if (G(A, B, C)) D.insert(C[0]);
    while (next_permutation(begin(C), end(C)));

    cout << size(D) << "\n";
    return 0;
}