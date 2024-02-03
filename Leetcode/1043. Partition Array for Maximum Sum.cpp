static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    struct SegTree {
        int N; vector<long long> A;
        SegTree (int S, vector<long long> &B) { N = S, A.assign(2 * N, LLONG_MIN); for (int i = 0; i < (int) size(B); i++) UPDATE(i, B[i]); }
    
        long long MAX (int L, int R) { long long S = LLONG_MIN; for (L += N, R += N; L <= R; L /= 2, R /= 2) { S = ((L & 1) ? max(S, A[L++]) : S), S = (!(R & 1) ? max(S, A[R--]) : S); } return S; }
        void UPDATE (int U, int V) { for (A[U + N] = V, U = ((U + N) / 2); U >= 1; U /= 2) A[U] = max(A[2 * U], A[2 * U + 1]); }
    };

    int maxSumAfterPartitioning(vector<int> &A, int K) {
        int N = size(A); vector<long long> DP(N + 1); vector<long long> B; for (auto &i : A) B.push_back(i); SegTree S(N, B);
        for (int i = 1; i <= N; i++) for (int j = 1; j <= min(i, K); j++) DP[i] = max(DP[i], DP[i - j] + S.MAX((i - j), i - 1) * j);

        return DP[N];
    }
};