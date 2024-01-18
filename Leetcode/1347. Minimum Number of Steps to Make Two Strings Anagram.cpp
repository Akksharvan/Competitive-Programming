static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int minSteps (string S, string T) {
        vector<int> F(26); int R = 0;
        
        for (char &c : S) F[c - 97]++;
        for (char &c : T) F[c - 97]--;
        
        for (int i = 0; i < 26; i++) R += max(0, F[i]);
        
        return R;
    }
};