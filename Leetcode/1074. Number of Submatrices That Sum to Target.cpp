static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &A, int T) {
        vector<vector<long long>> DP(size(A) + 1, vector<long long> (size(A[0]) + 1));
        for (int i = 1; i <= size(A); i++) for (int j = 1; j <= size(A[0]); j++) DP[i][j] = DP[i - 1][j] + DP[i][j - 1] + A[i - 1][j - 1] - DP[i - 1][j - 1];

        long long R = 0; for (int i = 1; i <= size(A); i++) for (int j = 1; j <= size(A[0]); j++) 
        for (int k = 1; k <= i; k++) for (int l = 1; l <= j; l++) R += (DP[i][j] - DP[i][l - 1] - DP[k - 1][j] + DP[k - 1][l - 1] == T);

        return R;
    }
};