#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q, K; cin >> Q >> K;
    vector<long long> DP(5001); DP[0] = 1;

    while (Q--) {
        char C; int X;
        cin >> C >> X;

        if (C == '+') for (int i = K; i >= X; i--) DP[i] += DP[i - X], DP[i] %= MOD;
        else for (int i = X; i <= K; i++) DP[i] -= DP[i - X], DP[i] %= MOD;

        cout << ((DP[K] + MOD) % MOD) << "\n";
    }

    return 0;
}