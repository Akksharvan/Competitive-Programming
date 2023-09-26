#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S; cin >> S;
    int X = (S[0] == 'a') + (S[1] == 'b') + (S[2] == 'c');

    if (X >= 1) cout << "YES" << "\n";
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