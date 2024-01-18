static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &A) {
        int N = size(A[0]); for (int i = 0; i < size(A); i++) N = max(N, i + (int) size(A[i]));
        vector<vector<int>> S(N + 1); vector<int> R;

        for (int i = 0; i < size(A); i++) for (int j = 0; j < size(A[i]); j++) S[j + i].push_back(A[i][j]);
        for (vector<int> &i : S) for (int j = size(i) - 1; j >= 0; j--) R.push_back(i[j]);

        return R;
    }
};