#include <bits/stdc++.h>
using namespace std;

void solve() {
    int B, C, H; cin >> B >> C >> H;
    cout << (2 + 2 * min(B - 1, C + H) - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}