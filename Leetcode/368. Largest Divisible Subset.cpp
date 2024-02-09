static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    vector<int> largestDivisibleSubset (vector<int> &A) {
        int N = size(A); vector<int> DP(N, 1), B(N, 0); sort(begin(A), end(A)); for (int i = 0; i < N; i++) B[i] = i;
        for (int i = 1; i < N; i++) for (int j = 0; j < i; j++) if (!(A[i] % A[j]) && DP[j] + 1 > DP[i]) DP[i] = DP[j] + 1, B[i] = j;

        vector<int> R; int I = distance(begin(DP), max_element(begin(DP), end(DP)));
        R.push_back(A[I]); while (B[I] != I) I = B[I], R.push_back(A[I]);

        return R;
    }
};