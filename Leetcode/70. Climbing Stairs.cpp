static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int climbStairs (int N) {
        vector<int> DP(2); DP[0] = 1, DP[1] = 1;
        for (int i = 2; i <= N; i++) DP[i & 1] += DP[!(i & 1)];

        return DP[(N & 1)];
    }
};