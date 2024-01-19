static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minFallingPathSum( vector<vector<int>> &A) {
        int DP[101][101]{}; int N = size(A);
        memset(DP, INT_MAX - 100000, sizeof(DP));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0) DP[i][j] = min(DP[i][j], A[i][j]);
                if (i == 0) continue; DP[i][j] = min(DP[i][j], DP[i - 1][j] + A[i][j]);

                if (j != 0) DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + A[i][j]);
                if (j != N - 1) DP[i][j] = min(DP[i][j], DP[i - 1][j + 1] + A[i][j]);
            }
        }

        return *min_element(begin(DP[N - 1]), end(DP[N - 1]));
    }
};