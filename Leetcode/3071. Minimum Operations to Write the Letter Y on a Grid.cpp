static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minimumOperationsToWriteY (vector<vector<int>> &A) {
        int N = size(A); set<pair<int, int>> B;
        
        for (int i = 0; i <= N / 2; i++) B.insert({i, i}), B.insert({i, (N - 1) - i});
        for (int i = N / 2; i < N; i++) B.insert({i, N / 2});
        
        int R = INT_MAX; array<int, 3> C{}, D{};
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { if (B.count({i, j})) D[A[i][j]]++; else C[A[i][j]]++; }
        
        R = min(R, (int) ((size(B) - D[0]) + min(C[0] + C[1], C[0] + C[2])));
        R = min(R, (int) ((size(B) - D[1]) + min(C[1] + C[0], C[1] + C[2])));
        R = min(R, (int) ((size(B) - D[2]) + min(C[2] + C[0], C[2] + C[1])));
        
        return R;
    }
};