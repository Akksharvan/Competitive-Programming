#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    if (N == 1) { cout << "NO" << "\n"; return; }

    long long B = 0, C = 0;
    for (long long &i : A) {
        if (i == 1) B++;
        else C += (i - 1);
    }

    if (C >= B) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}