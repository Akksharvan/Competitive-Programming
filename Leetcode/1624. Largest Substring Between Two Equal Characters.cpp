static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int maxLengthBetweenEqualCharacters (string S) {
        int N = size(S), R = -1; vector<int> A(26, 301);
        for (int i = 0; i < N; i++) A[S[i] - 97] = min(A[S[i] - 97], i), R = max(R, (i - A[S[i] - 97] - 1)); return R;
    }
};