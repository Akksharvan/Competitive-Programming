static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minTimeToVisitAllPoints (vector<vector<int>> &A) {
        int N = size(A), R = 0; for (int i = 0; i < N - 1; i++) R += max(abs(A[i][0] - A[i + 1][0]), abs(A[i][1] - A[i + 1][1])); return R;
    }
};