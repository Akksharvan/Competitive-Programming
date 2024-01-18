static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minCost(string S, vector<int> &A) {
        int N = size(S); vector<vector<int>> DP(2, vector<int> (26, INT_MAX - 1e9));
        fill(begin(DP[0]), end(DP[0]), 0); DP[0][S[0] - 97] = A[0];

        for (int i = 1; i < N; i++) {
            bool k = (i & 1); fill(begin(DP[k]), end(DP[k]), INT_MAX - 1e9);
            for (int j = 0; j < 26; j++) {
                if (j == (S[i] - 97)) DP[k][j] = min(DP[k][j], DP[!k][j] + A[i]);
                else DP[k][j] = min(DP[k][j], min(DP[!k][S[i] - 97], DP[!k][j] + A[i]));
            }
        }

        int R = INT_MAX; for (int i = 0; i < 26; i++) R = min(R, DP[(N - 1) & 1][i]);
        return R;
    }
};