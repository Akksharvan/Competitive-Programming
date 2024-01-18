class Solution {
public:
    int numberOfPoints(vector<vector<int>>& A) {
        array<int, 101> B{}; for (vector<int> &i : A) for (int j = i[0]; j <= i[1]; j++) B[j] = 1;
        return (accumulate(begin(B), end(B), 0));
    }
};