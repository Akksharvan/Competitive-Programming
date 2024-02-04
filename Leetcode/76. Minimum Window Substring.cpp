static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    inline bool F (vector<int> &A, vector<int> &B) {
        for (int i = 0; i < 58; i++) if (A[i] < B[i]) return 0;
        return 1;
    }

    string minWindow (string S, string T) {
        int N = size(S), M = size(T), I = 0, J = 0;
        pair<int, int> R = {INT_MAX, 0};

        vector<int> A(58), B(58);
        string K; for (auto &c : T) B[c - 65]++;

        while (I < N) {
            bool C = F(A, B); while (J < N && !C) A[S[J] - 65]++, J++, C = F(A, B);
            if (C) R = min(R, {(J - 1) - I + 1, I}); A[S[I] - 65]--, I++;
        }

        if (R.first == INT_MAX) return "";
        else return S.substr(R.second, R.first);
    }
};