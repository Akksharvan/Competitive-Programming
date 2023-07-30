#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T, L, R;
    cin >> T >> L >> R;

    array<long long, (int) 5e6 + 1> DP{};
    fill(begin(DP) + 2, end(DP), LLONG_MAX);

    for (int i = 2; i <= 5e6; i++) {
        DP[i] = min(DP[i], 1LL * i * (i - 1)) / 2;
    }

    for (int i = 2; i <= 5e6; i++) {
        for (int j = i; j <= 5e6; j += i) {
            DP[j] = min(DP[j], (j / i) * DP[i] + DP[(j / i)]);
        }
    }

    long long F = 0;
    for (int i = R; i >= L; i--) {
        F += (DP[i] % MOD);
        F *= (i != L ? T : 1);
        F %= MOD;
    }
 
    cout << (F % MOD) << "\n";
	return 0;
}