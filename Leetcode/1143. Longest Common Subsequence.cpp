static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int longestCommonSubsequence (string S1, string S2) {
        int N = size(S1), M = size(S2);
        vector<vector<int>> DP(N + 1, vector<int> (M + 1));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                if (S1[i - 1] == S2[j - 1]) DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
            }
        }

        return DP[N][M];
    }
};