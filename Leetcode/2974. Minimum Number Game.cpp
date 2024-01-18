class Solution {
public:
    vector<int> numberGame(vector<int> &A) {
        vector<int> R; sort(begin(A), end(A)); int N = size(A);
        for (int i = 0; i < N - 1; i += 2) R.push_back(A[i + 1]), R.push_back(A[i]); if (N & 1) R.push_back(A[N - 1]);
        
        return R;
    }
};