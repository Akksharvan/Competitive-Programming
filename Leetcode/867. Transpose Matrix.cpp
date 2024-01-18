static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        int N = size(A), M = size(A[0]); vector<vector<int>> R(M, vector<int> (N));
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) R[i][j] = A[j][i];

        return R;
    }
};