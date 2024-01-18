class Solution {
public:
    int singleNumber (vector<int>& A) {
        int R = 0; for (int &i : A) R ^= i;
        return R;
    }
};