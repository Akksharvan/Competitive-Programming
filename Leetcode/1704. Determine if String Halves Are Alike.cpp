static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool halvesAreAlike (string S) {
        int N = size(S), R1 = 0, R2 = 0;
        string V = "aeiouAEIOU";

        for (int i = 0; i < N / 2; i++) {
            char C1 = S[i]; if (V.find(C1) != string::npos) R1++;
            char C2 = S[i + N / 2]; if (V.find(C2) != string::npos) R2++;
        }

        return (R1 == R2);
    }
};