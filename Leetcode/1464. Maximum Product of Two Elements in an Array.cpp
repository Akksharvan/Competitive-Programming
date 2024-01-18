static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxProduct(vector<int> &A) {
        int N = size(A), I = -1, J = -1; for (int i = 0; i < N; i++) if (I == -1 || A[i] >= A[I]) I = i;
        for (int i = 0; i < N; i++) if (i != I && (J == -1 || A[i] >= A[J])) J = i;

        return ((A[I] - 1) * (A[J] - 1));
    }
};