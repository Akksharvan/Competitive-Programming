static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    struct SegTree {
        int N; vector<int> A;
        SegTree (int S, vector<int> &B) { N = S, A.assign(2 * N, 0); for (int i = 0; i < (int) size(B); i++) UPDATE(i, B[i]); }
    
        int MAX (int L, int R) { int S = INT_MIN; for (L += N, R += N; L <= R; L /= 2, R /= 2) { S = max(S, ((L & 1) ? A[L++] : 0)), S = max(S, (!(R & 1) ? A[R--] : 0)); } return S; }
        void UPDATE (int U, int V) { for (A[U + N] = V, U = ((U + N) / 2); U >= 1; U /= 2) A[U] = max(A[2 * U], A[2 * U + 1]); }
    };

    int minDifficulty(vector<int> &A, int D) {
        int N = size(A); int DP[11][301]{}; for (int i = 0; i <= 10; i++) memset(DP[i], -1, sizeof(DP[i])); SegTree S(N, A); DP[0][0] = 0;

        for (int i = 0; i < D; i++) for (int j = i; j <= N; j++) for (int k = j + 1; k <= N; k++) {
            if (DP[i][j] == -1 || (i == D - 1 && k != N)) continue;
            DP[i + 1][k] = min((DP[i + 1][k] == -1 ? INT_MAX : DP[i + 1][k]), (int) (DP[i][j] + S.MAX(j, k - 1)));
        }
        
        return DP[D][N];
    }
};