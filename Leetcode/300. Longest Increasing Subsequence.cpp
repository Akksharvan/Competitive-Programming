static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int BS (int A, int L, int H, vector<int> &DP) {
        while (L < H) {
            int M = L + (H - L + 1) / 2;
            if (DP[M] < A) L = M;
            else H = M - 1;
        }

        return L;
    }

    int lengthOfLIS (vector<int> &A) {
        int N = size(A); vector<int> DP(N + 1, 1e4 + 1); DP[0] = -(1e4 + 1);
        for (int &i : A) { int j = BS(i, 0, N, DP) + 1; DP[j] = min(DP[j], i); }

        for (int i = N; i >= 1; i--) if (DP[i] != 1e4 + 1) return i;
        return 0;
    }
};