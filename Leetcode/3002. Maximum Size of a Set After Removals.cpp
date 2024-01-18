class Solution {
public:
    int maximumSetSize (vector<int> &A, vector<int> &B) {
        int N = size(A);
        
        int NA = N / 2;
        int NB = N / 2;
        
        unordered_set<int> C;
        unordered_set<int> D;
        
        for (int i = 0; i < N; i++) {
            if (C.count(A[i])) NA--;
            if (D.count(B[i])) NB--;
            
            C.insert(A[i]);
            D.insert(B[i]);
        }
        
        for (int i = 0; i < N; i++) {
            if (NA <= 0) break;
            if (C.count(A[i]) && D.count(A[i])) C.erase(A[i]), NA--;
        }
        
        for (int i = 0; i < N; i++) {
            if (NB <= 0) break;
            if (D.count(B[i]) && C.count(B[i])) D.erase(B[i]), NB--;
        }
        
        unordered_set<int> E;
        
        for (const int &i : C) E.insert(i);
        for (const int &i : D) E.insert(i);
        
        return (size(E) - max(0, NA) - max(0, NB));
    }
};