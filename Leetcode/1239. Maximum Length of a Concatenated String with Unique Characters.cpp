static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    void F (vector<int> &A, string S) {
        for (char &c : S) A[c - 97]++;
    }

    int maxLength(vector<string> &A) {
        vector<int> DP(1 << 16);
        int N = size(A); DP[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < (1 << i); j++) {
                if (!DP[j]) continue; vector<int> B(26); F(B, A[i]);
                for (int k = 0; k < i; k++) if (j & (1 << k)) F(B, A[k]);

                bool C = 0; for (int &i : B) C |= (i > 1); if (C) continue;
                DP[((1 << i) | j)] = accumulate(begin(B), end(B), 0);
            }
        }

        DP[0] = 0; int R = 0;
        for (int i = 0; i < (1 << 16); i++) if (DP[i]) R = max(R, DP[i]);

        return R;
    }
};