static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxScore (string S) {
        int R1 = (S[0] == '0'), R2 = count(begin(S) + 1, end(S), '1'), R3 = R1 + R2, N = size(S);
        for (int i = 1; i < N - 1; i++) R1 += (S[i] == '0'), R2 -= (S[i] == '1'), R3 = max(R3, R1 + R2);

        return R3;
    }
};