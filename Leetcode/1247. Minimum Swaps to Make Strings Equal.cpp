class Solution {
public:
    int minimumSwap (string S1, string S2) {
        vector<char> A; vector<char> B; int C = 0;
        for (int i = 0; i < size(S1); i++) A.push_back(S1[i]), B.push_back(S2[i]);

        for (int i = 0; i < size(S1); i++) {
            if (A[i] == B[i]) continue;
            for (int j = i + 1; j < size(S1); j++) {
                if (A[j] == B[j]) continue;
                if (A[i] == A[j]) { swap(A[i], B[j]); C++; break; }
            }

            if (A[i] == B[i]) continue;
            for (int j = i + 1; j < size(S1); j++) {
                if (A[j] == B[j]) continue;
                if (A[i] != A[j]) { swap(B[i], B[j]); C += 2; break; }
            }
        }


        if (A != B) return -1;
        return C;
    }
};