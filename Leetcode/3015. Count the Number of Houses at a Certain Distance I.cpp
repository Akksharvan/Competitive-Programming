class Solution {
public:
    vector<int> countOfPairs (int N, int X, int Y) {
        vector<int> R(N); X--; Y--;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                R[min(abs(i - j) - 1, min(abs(i - X) + abs(Y - j), abs(i - Y) + abs(X - j)))]++;
            }
        }
        
        return R;
    }
};