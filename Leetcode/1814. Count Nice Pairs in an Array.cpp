static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int F (int X) {
        int R = 0; while (X) { R *= 10; R += (X % 10); X /= 10; }
        return R; 
    }

    int countNicePairs(vector<int> &A) {
        unordered_map<int, int> B; long long R = 0;
        for (int i = 0; i < size(A); i++) R += B[A[i] - F(A[i])], B[A[i] - F(A[i])]++;

        return (R % MOD);
    }
};