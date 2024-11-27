#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;

    vector<array<long long, 2>> L1(N + 1);
    vector<array<long long, 2>> L2(M + 1);

    cin >> L1[0][0] >> L1[0][1];
    cin >> L2[0][0] >> L2[0][1];

    string P1; cin >> P1;
    string P2; cin >> P2;

    map<char, array<long long, 2>> M1;
    
    M1['N'] = {0, 1}; M1['S'] = {0, -1};
    M1['E'] = {1, 0}; M1['W'] = {-1, 0};

    for (int i = 0; i < N; i++) {
        L1[i + 1][0] = L1[i][0] + M1[P1[i]][0];
        L1[i + 1][1] = L1[i][1] + M1[P1[i]][1];
    }

    for (int i = 0; i < M; i++) {
        L2[i + 1][0] = L2[i][0] + M1[P2[i]][0];
        L2[i + 1][1] = L2[i][1] + M1[P2[i]][1];
    }

    vector<vector<long long>> DP(N + 1);
    for (auto &i : DP) i.resize(M + 1, 1e9 + 7);

    DP[0][0] = 0;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            long long XC = (L1[i][0] - L2[j][0]) * (L1[i][0] - L2[j][0]);
            long long YC = (L1[i][1] - L2[j][1]) * (L1[i][1] - L2[j][1]);

            long long C = XC + YC;

            if (i > 0) DP[i][j] = min(DP[i][j], DP[i - 1][j] + C);
            if (j > 0) DP[i][j] = min(DP[i][j], DP[i][j - 1] + C);

            if (i > 0 && j > 0) DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + C);
        }
    }

    cout << DP[N][M] << "\n";
    return 0;
}