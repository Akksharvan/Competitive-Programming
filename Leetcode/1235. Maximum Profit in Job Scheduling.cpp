static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int F (int I, int L, int H, vector<array<int, 3>> &A) {
        while (L < H) {
            int M = L + (H - L) / 2;
            if (A[M][0] >= I) H = M;
            else L = M + 1;
        }
    
        return L;
    }

    int jobScheduling(vector<int> &A, vector<int> &B, vector<int> &C) {
        int N = size(A); vector<array<int, 3>> D(N);
        for (int i = 0; i < N; i++) D[i][0] = A[i], D[i][1] = B[i], D[i][2] = C[i];
        
        sort(begin(D), end(D));
        vector<int> DP(N + 1, 0);
    
        for (int i = 0; i <= N; i++) {
            if (i > 0) DP[i] = max(DP[i], DP[i - 1]);
            if (i == N) continue;
            
            int X = F(D[i][1], 0, N, D);
            DP[X] = max(DP[X], DP[i] + D[i][2]);
        }
    
        return DP[N];
    }
};