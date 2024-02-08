static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int numSquares (int N) {
        vector<int> DP(N + 1, INT_MAX / 2); DP[0] = 0;
        for (int i = 1; i <= N; i++) for (int j = 1; j * j <= i; j++) DP[i] = min(DP[i], DP[i - (j * j)] + 1);

        return DP[N];
    }
};