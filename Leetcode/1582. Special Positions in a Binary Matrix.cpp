static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int numSpecial(vector<vector<int>>& A) {
        int M = size(A), N = size(A[0]), R = 0; vector<int> B(M), C(N); for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (A[i][j] == 1) B[i]++, C[j]++;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (A[i][j] == 1 && B[i] == 1 && C[j] == 1) R++; return R;
    }
};