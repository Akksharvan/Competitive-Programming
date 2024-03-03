#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N; cin >> N;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    long long R1 = accumulate(begin(A), end(A), 0LL) / N;
    long long R2 = 0; for (long long i = 0; i < N; i++) {
        R2 += A[i]; if (R2 >= R1 * (i + 1)) continue;
        cout << "NO" << "\n"; return;
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