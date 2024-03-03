#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, R = LLONG_MAX; cin >> N;

    for (long long i = 0; i < 3; i++) {
        for (long long j = 0; j < 2; j++) {
            for (long long k = 0; k < 6; k++) {
                for (long long l = 0; l < 4; l++) {
                    if ((N - (i + 3 * j + 6 * k + 10 * l)) % 15) continue;
                    else if ((N - (i + 3 * j + 6 * k + 10 * l)) >= 0) R = min(R, i + j + k + l + ((N - (i + 3 * j + 6 * k + 10 * l)) / 15));
                }
            }
        }
    }

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}