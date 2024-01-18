class Solution {
public:
    int differenceOfSums (int N, int M) {
        long long R1 = 0, R2 = 0;
        for (long long i = 1; i <= N; i++) {
            if (i % M) R1 += i;
            else R2 += i;
        }
        
        return (R1 - R2);
    }
};