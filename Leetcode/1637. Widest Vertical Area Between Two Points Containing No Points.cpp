static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxWidthOfVerticalArea (vector<vector<int>> &A) {
        sort(begin(A), end(A)); int R = INT_MIN, N = size(A);
        for (int i = 0; i < N - 1; i++) R = max(R, A[i + 1][0] - A[i][0]);

        return R;
    }
};