static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int firstUniqChar (string S) {
        vector<int> A(26); for (auto &i : S) A[i - 97]++;
        int N = size(S); for (int i = 0; i < N; i++) if (A[S[i] - 97] == 1) return i;

        return -1;
    }
};