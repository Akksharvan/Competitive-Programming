static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& A) {
        int N = size(A), K1 = 0, K2 = accumulate(begin(A), end(A), 0); vector<int> R(N);
        for (int i = 0; i < N; i++) K2 -= A[i], R[i] = (((i) - (N - (i + 1))) * A[i]) - K1 + K2, K1 += A[i]; return R;
    }
};