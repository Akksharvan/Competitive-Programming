#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N; cin >> N; long long R = 0;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    long long S = accumulate(begin(A), end(A), 0); sort(begin(A), end(A));
    vector<vector<long long>> DP(N + 1, vector<long long> (S + 1)); DP[0][0] = 1;

    for (long long i = 1; i <= N; i++) {
        for (long long j = 0; j <= S; j++) {
            if (j <= A[i - 1]) R += (DP[i - 1][j] * A[i - 1]), R %= MOD;
            else R += (DP[i - 1][j] * (A[i - 1] + ((j - A[i - 1]) / 2) + ((j - A[i - 1]) & 1))), R %= MOD;
        }

        for (long long j = 0; j <= S; j++) {
            DP[i][j] += DP[i - 1][j]; DP[i][j] %= MOD;
            if (j >= A[i - 1]) DP[i][j] += DP[i - 1][j - A[i - 1]], DP[i][j] %= MOD;
        }
    }

    cout << R << "\n";
    return 0;
}