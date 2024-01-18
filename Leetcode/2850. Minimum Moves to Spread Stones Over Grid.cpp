class Solution {
public:
    int minimumMoves (vector<vector<int>>& A) {
        vector<pair<int, int>> B;
        vector<pair<int, int>> C;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!A[i][j]) B.push_back({i, j});
                else if (A[i][j] > 1) for (int k = 2; k <= A[i][j]; k++) C.push_back({i, j});
            }
        }
        
        sort(begin(B), end(B));
        int R = 1e5;
        
        do { int X = 0; for (int i = 0; i < size(C); i++) X += F(B[i], C[i]); R = min(R, X); }
        while (next_permutation(begin(B), end(B)));
        
        return R;
    }
    
    int F (pair<int, int> A, pair<int, int> B) {
        return abs(A.first - B.first) + abs(A.second - B.second);
    }
};