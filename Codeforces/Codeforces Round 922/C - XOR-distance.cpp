#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long A, B, R; cin >> A >> B >> R;
    long long C = 0; if (A < B) swap(A, B);

    vector<pair<long long, long long>> D;

    for (long long i = 0; i < 60; i++) {
        if (!(A & (1LL << i)) && !(B & (1LL << i))) continue;
        else if ((A & (1LL << i)) && (B & (1LL << i))) continue;

        D.push_back({i, (A & (1LL << i)) ? 1 : 0});
    }

    reverse(begin(D), end(D));
    for (long long i = 1; i < size(D); i++) {
        if (!D[i].second || (C | (1LL << D[i].first)) > R) continue;
        A ^= (1LL << D[i].first), B ^= (1LL << D[i].first), C |= (1LL << D[i].first);
    }

    cout << abs(A - B) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}