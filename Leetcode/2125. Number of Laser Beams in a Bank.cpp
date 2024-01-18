static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int numberOfBeams (vector<string> &A) {
        int N = size(A), R = 0; for (int i = 0; i < N; i++) {
            int B = count(begin(A[i]), end(A[i]), '1'), C = 0; if (!B) continue; int j = i;
            while (j + 1 < N) { j++; C = count(begin(A[j]), end(A[j]), '1'); if (C) { break; } }

            if (i == j) continue;
            else R += (B * C), i = j - 1;
        }

        return R;
    }
};