static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int countSubmatrices(vector<vector<int>> &A, int K) {
        int N = size(A), M = size(A[0]); vector<vector<int>> DP(N + 1, vector<int> (M + 1));
        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) DP[i][j] = DP[i - 1][j] + DP[i][j - 1] + A[i - 1][j - 1] - DP[i - 1][j - 1];
        
        int R = 0; for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) if (DP[i][j] - DP[0][j] - DP[i][0] + DP[0][0] <= K) R++;
        return R;
    }
};