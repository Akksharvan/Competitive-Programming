#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N; string S; cin >> S;
    string S2 = S; reverse(begin(S2), end(S2));

    if (S2 < S) cout << S2 << S << "\n";
    else cout << S << "\n";
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}