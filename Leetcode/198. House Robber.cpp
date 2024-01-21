static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int rob (vector<int> &A) {
        int N = size(A); if (N == 1) return A[0];
        vector<int> DP(2); DP[0] = A[0], DP[1] = max(A[0], A[1]);

        for (int i = 2; i < N; i++) DP[(i & 1)] = max(DP[!(i & 1)], DP[(i & 1)] + A[i]);
        return DP[((N - 1) & 1)];
    }
};