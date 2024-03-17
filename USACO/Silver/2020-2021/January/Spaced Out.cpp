#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; vector<vector<int>> A(N, vector<int> (N));
    for (auto &i : A) for (auto &j : i) cin >> j;

    int R1 = 0, R2 = 0;

    vector<vector<int>> S1(N, vector<int>(2));
    vector<vector<int>> S2(N, vector<int>(2));

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) S1[i][j % 2] += A[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) S2[j][i % 2] += A[i][j];

    for (int i = 0; i < N; i++) R1 += max(S1[i][0], S1[i][1]);
    for (int i = 0; i < N; i++) R2 += max(S2[i][0], S2[i][1]);

    cout << max(R1, R2) << "\n";
    return 0;
}