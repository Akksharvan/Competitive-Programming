class Solution {
public:
    int BS (int L, int H, int I, int X, int Y) {
        while (L < H) {
            int M = L + (H - L) / 2;
            if ((M - I) > ((abs(X - I) + 1) + (Y - M))) H = M;
            else L = M + 1;
        }
        
        return L;
    }
    
    vector<long long> countOfPairs (int N, int X, int Y) {
        vector<long long> R(N);
        if (X > Y) swap(X, Y); X--; Y--;
        
        if (X == Y) {
            for (int i = 0; i < N; i++) R[0] += 2, R[(N - 1) - i] -= 2;
            for (int i = 1; i < N; i++) R[i] += R[i - 1];
            
            return R;
        }
        
        for (int i = 0; i < N; i++) {
            if (i < X) {
                R[0] += 2; R[X - i] -= 2;
                int J = BS(X, Y, i, X, Y);
                
                if ((J - i) > ((X - i + 1) + (Y - J))) {
                    R[X - i] += 2, R[(X - i) + (Y - J + 1)] -= 2;
                    R[X - i] += 2, R[(X - i) + ((J - 1) - X)] -= 2;
                }
                else R[X - i] += 2, R[(X - i) + (Y - X)] -= 2;
                R[X - i + 1] += 2; R[(X - i + 1) + ((N - 1) - Y)] -= 2;
            }
            else if (i < Y) {
                int J = BS(i, Y, i, X, Y);
                if ((J - i) > ((i - X + 1) + (Y - J))) {
                    R[i - X] += 2, R[(i - X) + (Y - J + 1)] -= 2;
                    R[0] += 2, R[(J - 1) - i] -= 2;
                }
                else R[0] += 2, R[Y - i] -= 2;
                R[min(i - X + 1, Y - i)] += 2; R[min(i - X + 1, Y - i) + ((N - 1) - Y)] -= 2;
            }
            else {
                R[0] += 2;
                R[(N - 1) - i] -= 2;
            }
        }
        
        for (int i = 1; i < N; i++) R[i] += R[i - 1];
        return R;
    }
};