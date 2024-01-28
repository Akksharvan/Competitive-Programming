static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int countKeyChanges (string S) {
        int N = size(S); int R = 0;
        for (int i = 1; i < N; i++) R += (tolower(S[i]) != tolower(S[i - 1]));
        
        return R;
    }
};