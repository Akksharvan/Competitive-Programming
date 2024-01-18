static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool isPathCrossing (string S) {
        int X = 0, Y = 0;
        set<pair<int, int>> B; B.insert({X, Y});

        for (char &c : S) {
            X += ((c == 'E' || c == 'W') ? (c == 'E' ? 1 : -1) : 0);
            Y += ((c == 'N' || c == 'S') ? (c == 'N' ? 1 : -1) : 0);

            if (B.count({X, Y})) return 1;
            else B.insert({X, Y});
        }

        return 0;
    }
};