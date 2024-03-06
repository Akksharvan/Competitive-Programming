#include <bits/stdc++.h>
using namespace std;

inline long long F (long long X) {
    return (X * (X + 1)) / 2;
}

void solve() {
    long long N, C; cin >> N >> C;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    long long R = 0, E = 0, O = 0;
    for (auto &i : A) R += (i / 2 + 1) + (C - i + 1), E += ((i & 1) ? 0 : 1), O += ((i & 1) ? 1 : 0);

    R -= (F(E) + F(O)); R = F(C + 1) - R;
    cout << R << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}