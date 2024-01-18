class Solution {
public:
    int uniquePaths(int M, int N) {
        vector<vector<int>> DP(M + 1, vector<int> (N + 1)); DP[1][1] = 1;
        for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) DP[i][j] = max(1, DP[i - 1][j] + DP[i][j - 1]);

        return DP[M][N];
    }
};