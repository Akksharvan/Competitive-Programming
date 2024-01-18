class Solution {
public:
    long long countInterestingSubarrays(vector<int>& A, int MOD, int K) {
        long long R = 0; int N = (int) size(A); vector<long long> DP(N + 1);
        for (int i = 1; i <= N; i++) DP[i] = DP[i - 1] + (A[i - 1] % MOD == K);
        
        map<long long, long long> B;
        for (int i = 0; i <= N; i++) R += B[DP[i] % MOD], B[(DP[i] + K) % MOD]++;
        
        return R;
    }
};