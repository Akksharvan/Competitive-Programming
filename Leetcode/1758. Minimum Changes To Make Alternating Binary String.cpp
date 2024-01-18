static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minOperations (string S1) {
        int N = size(S1); int R2 = 0, R3 = 0;
        for (int i = 0; i < N; i++) R2 += (S1[i] != (i & 1 ? '1' : '0')), R3 += (S1[i] != (i & 1 ? '0' : '1'));

        return min(R2, R3);
    }
};