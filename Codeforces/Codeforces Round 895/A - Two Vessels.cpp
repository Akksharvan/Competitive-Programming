#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    if (abs(A - B) % (2 * C)) cout << ((abs(A - B) / (2 * C)) + 1) << "\n";
    else cout << (abs(A - B) / (2 * C)) << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}