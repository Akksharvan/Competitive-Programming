#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    
    for (int i = 2; i < 100; i++) { if ((A % i) && (B % i) && (C % i)) { cout << i << "\n"; return; } }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) solve();
    
    return 0;
}