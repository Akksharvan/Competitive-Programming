static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int buyChoco (vector<int> &A, int B) {
        pair<int, int> P = {0, 1}; int N = size(A);
        if (A[P.first] > A[P.second]) swap(P.first, P.second);

        for (int i = 2; i < N; i++) {
            if (A[i] < A[P.first]) P.second = (A[P.first] < A[P.second] ? P.first : P.second), P.first = i;
            else if (A[i] < A[P.second]) P.second = i;
        }

        return ((B >= A[P.first] + A[P.second]) ? (B - (A[P.first] + A[P.second])) : B);
    }
};