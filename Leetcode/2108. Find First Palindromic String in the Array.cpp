static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    inline bool F (string &A) { int N = size(A); for (int i = 0; i < N / 2; i++) if (A[i] != A[(N - 1) - i]) return 0; return 1; }
    string firstPalindrome (vector<string> &A) { for (auto &i : A) if (F(i)) return i; return ""; }
};