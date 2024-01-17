class Solution {
public:
    int removeDuplicates (vector<int> &A) {
        return distance(begin(A), unique(begin(A), end(A)));
    }
};