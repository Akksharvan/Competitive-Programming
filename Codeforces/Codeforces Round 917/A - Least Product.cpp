#include <bits/stdc++.h>
using namespace std;

bool F (vector<long long> &A) {
    int K = 0; for (long long &i : A) if (i < 0) K++;
    return (!(K & 1) ? 1 : 0);
}

void solve () {
    long long N; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    if (count(begin(A), end(A), 0)) { cout << 0 << "\n"; return; }
    if (F(A)) { cout << 1 << "\n"; cout << 1 << " " << 0 << "\n"; return; }

    cout << 0 << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}