class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>> &A) {
        int B = 0, C = 0, N = size(A);
        for (int i = 0; i < N; i++) {
            if (A[i][0] * A[i][0] + A[i][1] * A[i][1] > B) B = A[i][0] * A[i][0] + A[i][1] * A[i][1], C = A[i][0] * A[i][1];
            else if (A[i][0] * A[i][0] + A[i][1] * A[i][1] == B) C = max(C, A[i][1] * A[i][0]);
        }
        
        return C;
    }
};