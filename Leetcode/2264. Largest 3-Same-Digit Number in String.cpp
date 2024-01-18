static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    string largestGoodInteger (string S) {
        string R; int N = size(S);

        for (int i = 0; i < N - 2; i++) {
            if (S[i] == S[i + 1] && S[i] == S[i + 2]) {
                if (!(R.empty() || R[0] < S[i])) { i += 2; continue; }
                else { R.clear(); R += S[i]; R += S[i]; R += S[i]; i += 2; continue; }
            }
        }

        return R;
    }
};