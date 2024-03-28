#include <bits/stdc++.h>
using namespace std;

bool F (string S, int L, int R) {
    return (S[L] != S[R]);
}

bool G (array<int, 26> &A) {
    int R = 0; for (auto &i : A) if (i) R++;
    return (R >= 3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S; cin >> S; int Q, N = size(S); cin >> Q;
    vector<array<int, 26>> DP(N, array<int, 26>());

    for (int i = 0; i < N; i++) DP[i][S[i] - 'a']++;
    for (int i = 1; i < N; i++) for (int j = 0; j < 26; j++) DP[i][j] += DP[i - 1][j];

    while (Q--) {
        int L, R; cin >> L >> R; L--, R--; array<int, 26> B{};
        
        for (int i = 0; i < 26; i++) B[i] = DP[R][i];
        if (L) for (int i = 0; i < 26; i++) B[i] -= DP[L - 1][i];

        if (L == R || F(S, L, R) || G(B)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}