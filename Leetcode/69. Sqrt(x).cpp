class Solution {
public:
    int mySqrt(int x) {
        long long L = 0;
        long long H = 5e4;

        while (L < H) {
            long long M = L + (H - L + 1) / 2;
            if ((M * M) <= x) L = M;
            else H = M - 1;
        }

        return L;
    }
};