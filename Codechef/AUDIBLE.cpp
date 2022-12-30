#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int X;
        cin >> X;
        cout << ((X >= 67 && X <= 45000) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}