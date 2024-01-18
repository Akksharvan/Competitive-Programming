class Solution {
public:
    int maxProfit (vector<int>& A) {
        int R = 0, P = A[0];
        for (int &i : A) P = min(P, i), R = max(R, i - P);

        return R;
    }
};