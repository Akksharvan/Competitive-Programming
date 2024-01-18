static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &A, vector<int>& L, vector<int>& R) {
        int N = size(A), M = size(L); vector<bool> Z(M, 1);
        for (int i = 0; i < M; i++) {
            vector<int> B; for (int j = L[i]; j <= R[i]; j++) B.push_back(A[j]);
            sort(begin(B), end(B)); if (size(B) == 1) continue;
            
            for (int j = 2; j < size(B); j++) {  if (B[j] - B[j - 1] != B[1] - B[0]) Z[i] = 0; }
        }

        return Z;
    }
};