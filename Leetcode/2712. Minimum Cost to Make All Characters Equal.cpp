class Solution {
public:
    long long minimumCost(string s) {
        int n = (int) s.size();
        vector<vector<long long>> dp(4, vector<long long> (n + 2));
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                dp[0][i + 1] = dp[1][i] + i + 1;
                dp[1][i + 1] = dp[1][i];
            }
            else {
                dp[0][i + 1] = dp[0][i];
                dp[1][i + 1] = dp[0][i] + i + 1;
            }
        }
        
        for (int i = n; i >= 1; i--) {
            if (s[i - 1] == '1') {
                dp[2][i] = dp[3][i + 1] + n - i + 1;
                dp[3][i] = dp[3][i + 1];
            }
            else {
                dp[2][i] = dp[2][i + 1];
                dp[3][i] = dp[2][i + 1] + n - i + 1;
            }
        }
        
        long long res = LLONG_MAX;
        for (int i = 0; i <= n; i++) {
            res = min(res, (long long) dp[0][i] + dp[2][i + 1]);
            res = min(res, (long long) dp[1][i] + dp[3][i + 1]);
        }
        
        return res;
    }
};