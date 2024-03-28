#include <bits/stdc++.h>
using namespace std;

const int MOD = 2019;

long long BP (long long A, long long B, long long M) {
    A %= M; long long R = 1;
    while (B > 0) R *= ((B & 1) ? A : 1), R %= M, A *= A, A %= M, B >>= 1;
    
    return R;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S; cin >> S; int N = size(S);
    vector<int> A(N); for (int i = 0; i < N; i++) A[i] = (S[i] - '0');

    vector<int> DP(N + 1); DP[N] = 0;
    for (int i = N - 1; i >= 0; i--) DP[i] = BP(10, N - (i + 1), MOD) * A[i] + DP[i + 1], DP[i] %= MOD;

    map<int, long long> B; for (auto &i : DP) B[i]++;
    long long R = 0; for (auto &[i, j] : B) R += (j * (j - 1)) / 2;

    cout << R << "\n";
    return 0;
}