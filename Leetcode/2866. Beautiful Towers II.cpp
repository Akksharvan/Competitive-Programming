class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) {
        int N = size(A); vector<long long> DP1(N), DP2(N);
        stack<pair<int, int>> B, C; B.push({A[0], 0}), C.push({A[N - 1], N - 1});
        
        DP1[0] = A[0], DP2[N - 1] = A[N - 1];
        vector<int> D(N, -1), E(N, -1);
        
        for (int i = 1; i < N; i++) {
            while (!B.empty() && B.top().first >= A[i]) B.pop();
            if (!B.empty()) D[i] = B.top().second;
            
            B.push({A[i], i});
        }
        
        for (int i = N - 2; i >= 0; i--) {
            while (!C.empty() && C.top().first >= A[i]) C.pop();
            if (!C.empty()) E[i] = C.top().second;
            
            C.push({A[i], i});
        }
            
        for (long long i = 1; i < N; i++) {
            if (D[i] == -1) DP1[i] = (i + 1) * (A[i] * 1LL);
            else DP1[i] = DP1[D[i]] + ((i - D[i]) * (A[i] * 1LL));
        }
        
        for (long long i = N - 2; i >= 0; i--) {
            if (E[i] == -1) DP2[i] = (N - i) * (A[i] * 1LL);
            else DP2[i] = DP2[E[i]] + ((E[i] - i) * (A[i] * 1LL));
        }
        
        long long R = 0;
        for (long long i = 0; i < N; i++) R = max(R, DP1[i] + DP2[i] - A[i]);
    
        return R;
    }
};