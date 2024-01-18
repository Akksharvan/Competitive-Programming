static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    const long long MOD = 1e9 + 7;
    int numberOfWays (string A) {
        int N = size(A); vector<pair<long long, long long>> B;
        pair<long long, long long> C = {0, 0}; bool D = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] == 'S' && !D) D = 1, C.first = i;
            else if (A[i] == 'S' && D) D = 0, C.second = i, B.push_back(C);
        }

        if (B.empty() || D) return 0;
        if (size(B) == 1) return 1;
        
        long long R = 1; N = size(B);
        for (int i = 1; i < N; i++) R *= (B[i].first - B[i - 1].second), R %= MOD;

        return R;
    }
};