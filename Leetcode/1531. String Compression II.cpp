class Solution {
public:
    int getLengthOfOptimalCompression (string S, int K) {
        int N = size(S); int DP1[101][101]{}; for (int i = 0; i <= N; i++) for (int j = 0; j <= K; j++) DP1[i][j] = (i == 0 ? 0 : INT_MAX - 100);
        int DP2[26][101]{}; for (int i = 0; i < 26; i++) for (int j = 1; j <= N; j++) DP2[i][j] += DP2[i][j - 1] + (S[j - 1] - 97 != i);

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                for (int k = i; k <= N; k++) {
                    for (int l = 0; l < 26; l++) {
                        DP1[i][j] = min(DP1[i][j], DP1[i][max(0, j - 1)]);
                        int A = DP2[l][k] - DP2[l][i - 1], B = (k - i + 1) - A;
                        
                        if (A + j > K) continue;
                        if (B == 0) DP1[k][j + A] = min(DP1[k][j + A], DP1[i - 1][j]);

                        else if (B == 1) DP1[k][j + A] = min(DP1[k][j + A], DP1[i - 1][j] + 1);
                        else if (B <= 9) DP1[k][j + A] = min(DP1[k][j + A], DP1[i - 1][j] + 2);
                        else if (B <= 99) DP1[k][j + A] = min(DP1[k][j + A], DP1[i - 1][j] + 3);
                        else if (B >= 100) DP1[k][j + A] = min(DP1[k][j + A], DP1[i - 1][j] + 4);
                    }
                }
            }
        }

        return DP1[N][K];
    }
};