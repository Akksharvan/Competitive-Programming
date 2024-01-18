class Solution {
public:
    const long long MOD = 1e9 + 7;
    
    int maxSum (vector<int> &A, int K) {
        vector<int> B(32); for (int &i : A) for (int j = 0; j < 32; j++) B[j] += ((i >> j) & 1);
        long long R = 0; for (int i = 0; i < K; i++) { long long C = 0; for (int j = 0; j < 32; j++) { C += (B[j] > 0 ? (1 << j) : 0); B[j]--; } R += (C * C); R %= MOD; }
    
        return (R % MOD);
    }
};