#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A + B >= 10) { cout << "YES" << "\n"; return; }
    if (B + C >= 10) { cout << "YES" << "\n"; return; }
    if (A + C >= 10) { cout << "YES" << "\n"; return; }

    cout << "NO" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}