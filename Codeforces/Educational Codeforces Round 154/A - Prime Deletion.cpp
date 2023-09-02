#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S; cin >> S;

    if (S.find('1') < S.find('7')) cout << "17" << "\n";
    else cout << "71" << "\n";
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}