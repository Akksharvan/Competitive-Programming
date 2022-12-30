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
        cout << ((X > 100) ? X - 10 : X) << "\n";
    }
    
    return 0;
}