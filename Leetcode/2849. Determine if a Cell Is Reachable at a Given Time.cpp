class Solution {
public:
    bool isReachableAtTime (long long A, long long B, long long C, long long D, long long T) {
        long long X = min(abs(C - A), abs(D - B));
        X += abs(C - A) - min(abs(C - A), abs(D - B)); X += abs(D - B) - min(abs(C - A), abs(D - B));
        
        if (X <= T) {
            if (T - X == 1 && A == C && B == D) return 0;
            else return 1;
        }
        else return 0;
    }
};