static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool makeEqual(vector<string> &A) {
        vector<int> B(26); for (string &i : A) for (char &j : i) B[j - 97]++;
        for (int &i : B) if (i % size(A)) return 0; return 1;
    }
};