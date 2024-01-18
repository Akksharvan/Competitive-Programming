static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int countCharacters(vector<string> &A, string B) {
        array<int, 26> C{}, D{}; int R = 0;
        for (char &c : B) C[(c - 97)]++;

        for (string &i : A) {
            fill(begin(D), end(D), 0); bool F = 1; for (char &c : i) { D[(c - 97)]++; }
            for (int j = 0; j < 26; j++) { if (D[j] > C[j]) { F = 0; break; } } R += (F ? size(i) : 0);
        }

        return R;
    }
};