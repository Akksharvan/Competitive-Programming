static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    string largestOddNumber (string S) {
        while (!S.empty() && !((int) S.back() % 2)) S.pop_back();
        return S;
    }
};