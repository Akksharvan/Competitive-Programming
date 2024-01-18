static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxProductDifference (vector<int> &A) {
        int B = -1, C = -1, D = -1, E = -1, N = size(A);

        for (int i = 0; i < N; i++) if (B == -1 || A[i] > A[B]) B = i;
        for (int i = 0; i < N; i++) if (i != B && (C == -1 || A[i] > A[C])) C = i;

        for (int i = 0; i < N; i++) if (D == -1 || A[i] < A[D]) D = i;
        for (int i = 0; i < N; i++) if (i != D && (E == -1 || A[i] < A[E])) E = i;

        return (A[B] * A[C]) - (A[D] * A[E]);
    }
};