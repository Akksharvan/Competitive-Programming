static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    int findSpecialInteger(vector<int> &A) {
        int N = size(A);

        for (int i = 0; i < N; i++) {
            int j = i; while (j + 1 < N && A[i] == A[j + 1]) j++;
            if ((j - i + 1) * 4 > N) return A[i]; i = j;
        }

        return A[N - 1];
    }
};