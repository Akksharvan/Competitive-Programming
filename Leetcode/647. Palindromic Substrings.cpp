static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int countSubstrings (string S) {
        int R = 0, N = size(S);
        vector<bitset<1000>> DP(N);

        for (int i = N - 1; i >= 0; i--) for (int j = i; j < N; j++) {
            if (!(S[i] == S[j])) continue;
            if (i == j || j == i + 1 || DP[i + 1][j - 1]) DP[i][j] = 1, R++;
        }

        return R;
    }
};