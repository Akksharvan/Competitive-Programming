class Solution {
public:
    const long long MOD = 1e9 + 7;

    int kInversePairs (int N, int K) {
        vector<vector<long long>> DP1(2, vector<long long> (K + 1));
        vector<vector<long long>> DP2(2, vector<long long> (K + 2));
        
        for (int i = 1; i <= N; i++) for (int j = 0; j <= K; j++) {
            if (j == 0) DP1[i][j] = 1, DP2[i][j + 1] = 1; if (j == 0) continue;
            int k = max(0, j - (i - 1)); DP2[i][j + 1] += DP2[i][j], DP2[i][j + 1] %= MOD;
            
            DP1[i][j] += (DP2[i - 1][j + 1] - DP2[i - 1][k]), DP1[i][j] %= MOD;
            DP2[i][j + 1] += DP1[i][j], DP2[i][j + 1] %= MOD;
        }

        return ((DP1[N][K] + MOD) % MOD);
    }
};