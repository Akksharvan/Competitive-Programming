static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int numberOfMatches (int N) {
        if (N == 1) return 0; if (N == 2) return 1;
        return (N / 2) + numberOfMatches((N / 2) + ((N % 2) ? 1 : 0));
    }
};