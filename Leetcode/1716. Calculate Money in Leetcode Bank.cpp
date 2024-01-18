static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int F (int N, int K) {
        if (N <= 7) return (((N * (N + 1)) / 2) + (K * N));
        else return (28 + (7 * K) + F(N - 7, K + 1));
    }

    int totalMoney (int N) {
        return F(N, 0);
    }
};