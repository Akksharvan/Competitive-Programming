class Solution {
public:
    vector<int> getRow (int N) {
        N++; vector<int> A(1, 1);
        if (N == 1) return A;

        for (long long i = 1; i <= (N - 2) / 2 + ((N % 2) ? 1 : 0); i++) A.push_back(A[i - 1] * (N - i) / i);
        int R = ((N % 2) ? (size(A) - 2) : (size(A) - 1)); for (int i = R; i >= 0; i--) A.push_back(A[i]);

        return A;
    }
};