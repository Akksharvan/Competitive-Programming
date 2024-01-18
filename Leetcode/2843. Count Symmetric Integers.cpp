class Solution {
public:
    bool F (int i) {
        vector<int> A; while (i) { A.push_back(i % 10); i /= 10; }
        if (size(A) % 2) return 0;
        
        int B = 0, C = 0;
        for (int j = 0; j < size(A) / 2; j++) B += A[j];
        
        reverse(begin(A), end(A));
        for (int j = 0; j < size(A) / 2; j++) C += A[j];
        
        return (B == C);
    }
    int countSymmetricIntegers(int low, int high) {
        int R = 0;
        for (int i = low; i <= high; i++) if (F(i)) R++;
        
        return R;
    }
};