#include <bits/stdc++.h>
using namespace std;

void solve() {
    array<array<char, 8>, 8> G;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (G[i][j] == '.') continue;

            for (int k = i; k < 8; k++) {
                if (G[k][j] == '.') {
                    cout << "\n"; return;
                }

                cout << G[k][j];

                if (k == 7) {
                    cout << "\n";
                    return;
                }
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}