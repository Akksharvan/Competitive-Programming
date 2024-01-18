class Solution {
public:
    int F (vector<int> &A, vector<long long> &B, int L, int R, int H, int K) {
        while (L < R) {
            long long M = L + (R - L) / 2;
            if ((A[H - 1] * (H - M + 1)) - (B[H] - B[M - 1]) <= K) R = M;
            else L = M + 1;
        }
        return (H - L + 1);
    }

    int maxFrequency(vector<int>& A, int K) {
        sort(begin(A), end(A)); int N = size(A), R = 0;
        vector<long long> B(N + 1); for (int i = 1; i <= N; i++) B[i] += A[i - 1] + B[i - 1];

        for (int i = 0; i < N; i++) R = max(R, F(A, B, 1, i + 1, i + 1, K));
        return R;
    }
};