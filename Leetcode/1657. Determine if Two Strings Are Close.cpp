static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool closeStrings (string S1, string S2) {
        int N = size(S1); if (N != size(S2)) return 0;

        vector<int> F1(26), F2(26); for (int i = 0; i < N; i++) F1[S1[i] - 97]++, F2[S2[i] - 97]++;
        for (int i = 0; i < 26; i++) if ((F1[i] && !F2[i]) || (!F1[i] && F2[i])) return 0;

        multiset<int> M1, M2; for (int i = 0; i < 26; i++) M1.insert(F1[i]), M2.insert(F2[i]);
        return (M1 == M2);
    }
};