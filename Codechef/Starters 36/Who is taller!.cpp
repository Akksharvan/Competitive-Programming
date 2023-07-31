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
        cout << ((X > Y) ? "A" : "B") << "\n";
    }
    
    return 0;
}