class Solution {
public:
    vector<vector<int>> generate (int R) {
        vector<vector<int>> A;
        for (int i = 1; i <= R; i++) { vector<int> B(i, ((i == 1) ? (1) : (0))); A.push_back(B); }

        for (int i = 0; i < (R - 1); i++) {
            for (int j = 0; j <= i; j++) {
                A[i + 1][j] += A[i][j];
                A[i + 1][j + 1] += A[i][j];
            }
        }

        return A;
    }
};