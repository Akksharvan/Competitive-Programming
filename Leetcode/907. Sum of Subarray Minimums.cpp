static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int> &A) {
        int N = size(A);
        long long R = 0;

        stack<pair<int, int>> S;
        vector<long long> B(N), C(N);

        for (int i = 0; i < N; i++) {
            while (!S.empty() && S.top().first >= A[i]) S.pop();
            B[i] = (S.empty() ? -1 : S.top().second); S.push({A[i], i});
        }

        while (!S.empty()) S.pop();

        for (int i = N - 1; i >= 0; i--) {
            while (!S.empty() && S.top().first > A[i]) S.pop();
            C[i] = (S.empty() ? N : S.top().second); S.push({A[i], i});
        }

        for (int i = 0; i < N; i++) R += A[i] * (((C[i] - i) * (i - B[i])) % MOD), R %= MOD;
        return R;
    }
};