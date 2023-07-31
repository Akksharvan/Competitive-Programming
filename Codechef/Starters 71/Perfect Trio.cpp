#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        array<int, 3> ABC;
        cin >> ABC[0] >> ABC[1] >> ABC[2];
        sort(ABC.begin(), ABC.end());
        cout << (((ABC[0] + ABC[1]) == ABC[2]) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}