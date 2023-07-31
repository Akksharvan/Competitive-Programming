#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int X, H;
        cin >> X >> H;
        cout << ((X >= H) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}