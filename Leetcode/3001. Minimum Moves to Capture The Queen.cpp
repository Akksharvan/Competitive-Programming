class Solution {
public:
    int minMovesToCaptureTheQueen (int A, int B, int C, int D, int E, int F) {
        if (A == E) {
            if (C != E) return 1;
            else if (!((B < D && D < F) || (F < D && D < B))) return 1;
        }
        
        if (B == F) {
            if (D != F) return 1;
            else if (!((A < C && C < E) || (E < C && C < A))) return 1;
        }
        
        if (abs(C - E) == abs(D - F)) {
            if (!(abs(A - C) == abs(B - D))) return 1;
            else if (abs(A - C) > abs(C - E)) return 1;
            else if ((A - C) < 0 && (E - C) > 0) return 1;
            else if ((A - C) > 0 && (E - C) < 0) return 1;
            else if ((B - D) < 0 && (F - D) > 0) return 1;
            else if ((B - D) > 0 && (F - D) < 0) return 1;
        } 
        
        return 2;
    }
};