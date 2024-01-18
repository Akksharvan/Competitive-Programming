static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool isAnagram (string S, string T) {
        vector<int> A(26), B(26); for (char &c : S) A[c - 97]++;
        for (char &c : T) B[c - 97]++; return (A == B);
    }
};