static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int numDecodings (string S) {
        int N = size(S); vector<int> DP(N);

        for (int i = 0; i < N; i++) {
            if (i == 0) DP[i] = (S[i] >= '1');
            else if (i == 1) DP[i] = (S[i] >= '1' ? DP[0] : 0) + (S[0] == '1' || (S[0] == '2' && S[1] <= '6'));
            else DP[i] = (S[i] >= '1' ? DP[i - 1] : 0) + ((S[i - 1] == '1' || (S[i - 1] == '2' && S[i] <= '6')) ? DP[i - 2] : 0);
        }

        return DP[N - 1];
    }
};