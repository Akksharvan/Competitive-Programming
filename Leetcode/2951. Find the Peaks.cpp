static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> findPeaks(vector<int> &A) {
        int N = size(A); vector<int> R;
        for (int i = 1; i < N - 1; i++) { if (A[i] > A[i - 1] && A[i] > A[i + 1]) { R.push_back(i); } }
        
        return R;
    }
};