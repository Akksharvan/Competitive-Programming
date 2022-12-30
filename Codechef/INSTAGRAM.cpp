#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int X, Y;
        cin >> X >> Y;
        cout << ((X > (10 * Y)) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}