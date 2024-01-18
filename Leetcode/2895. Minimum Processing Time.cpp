class Solution {
public:
    int minProcessingTime(vector<int>& A, vector<int>& B) {
        sort(begin(A), end(A)); sort(rbegin(B), rend(B));
        int R = 0; for (int i = 0; i < size(A); i++) {
            R = max(R, A[i] + B[i * 4]); R = max(R, A[i] + B[i * 4 + 1]);
            R = max(R, A[i] + B[i * 4 + 2]), R = max(R, A[i] + B[i * 4 + 3]);
        }
        
        return R;
    }
};