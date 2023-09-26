#include <bits/stdc++.h>
using namespace std;

void solve() {
    int R = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            char c; cin >> c;
            if (c == '.') continue;

            int x = 0, y = 0;

            if (i <= 5) x = i;
            else x = 5 - (i - 6);

            if (j <= 5) y = j;
            else y = 5 - (j - 6);

            R += min(x, y);
        }
    }

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}