static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numRollsToTarget (int N, int K, int T) {
        vector<vector<int>> DP(T + 1, vector<int> (N + 1)); DP[0][0] = 1;
        for (int i = 1; i <= T; i++) for (int j = 1; j <= N; j++) for (int k = 1; k <= K; k++) { if (k > i) break; DP[i][j] += DP[i - k][j - 1]; DP[i][j] %= MOD; }
        
        return DP[T][N];
    }
};