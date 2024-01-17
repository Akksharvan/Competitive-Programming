#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, F, A, B, T = 0;
    cin >> N >> F >> A >> B;

    vector<long long> M(N);
    for (long long &i : M) cin >> i;

    for (long long &i : M) {
        if ((i - T) * A <= B) F -= (i - T) * A;
        else F -= B; T = i;

        if (F <= 0) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}