static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    const int MOD = 1e9 + 7;
    int knightDialer (int N) {
        vector<vector<int>> DP(2, vector<int> (10));
        fill(begin(DP[0]), end(DP[0]), 1);

        for (int i = 1; i < N; i++) {
            int n = (i & 1), p = (1 - n); fill(begin(DP[n]), end(DP[n]), 0); auto F = [&] (int a, int b) { DP[n][a] += DP[p][b]; DP[n][a] %= MOD; };
            F(0, 4), F(0, 6); F(1, 6), F(1, 8); F(2, 7), F(2, 9); F(3, 4), F(3, 8); F(4, 0), F(4, 3), F(4, 9); F(6, 0), F(6, 1), F(6, 7); F(7, 2), F(7, 6); F(8, 1), F(8, 3); F(9, 2), F(9, 4);
        }

        int R = 0; for (int i = 0; i <= 9; i++) R += DP[(N - 1) & 1][i], R %= MOD;
        return R;
    }
};