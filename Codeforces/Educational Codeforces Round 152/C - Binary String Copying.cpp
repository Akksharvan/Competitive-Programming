#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M; cin >> N >> M;
    string S; cin >> S;

    vector<vector<int>> DP(2, vector<int> (N, -1));
    DP[0][0] = (S[0] == '0' ? 0 : -1); DP[1][N - 1] = (S[N - 1] == '1' ? N - 1 : -1);

    for (int i = 1; i < N; i++) {
        if (S[i] == '0') DP[0][i] = i;
        else DP[0][i] = DP[0][i - 1];
    }

    for (int i = N - 2; i >= 0; i--) {
        if (S[i] == '1') DP[1][i] = i;
        else DP[1][i] = DP[1][i + 1];
    }

    set<pair<int, int>> E;
    for (int i = 0; i < M; i++) {
        int L, R; cin >> L >> R;

        if (DP[0][R - 1] == -1 || DP[0][R - 1] < L) E.insert({-1 , -1});
        else if (DP[1][L - 1] == -1 || DP[1][L - 1] > R) E.insert({-1, -1});
        else if (DP[0][R - 1] < DP[1][L - 1]) E.insert({-1, -1});
        else E.insert({DP[1][L - 1], DP[0][R - 1]});
    }

    cout << size(E) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}