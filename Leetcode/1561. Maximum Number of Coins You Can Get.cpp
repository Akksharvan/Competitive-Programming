static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxCoins(vector<int>& A) {
        sort(begin(A), end(A)); int N = size(A), S = N / 3, R = 0;
        for (int i = S; i < N; i += 2) R += A[i]; return R;
    }
};