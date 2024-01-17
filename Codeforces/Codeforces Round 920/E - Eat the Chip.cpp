#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long H, W, X1, Y1, X2, Y2;
    cin >> H >> W >> X1 >> Y1 >> X2 >> Y2;

    if (X1 >= X2) cout << "DRAW" << "\n";
    else if (!(abs(X1 - X2) % 2)) {
        if (Y1 < Y2) {
            if (max(1LL, (Y1 - abs(X1 - X2) / 2)) < max(1LL, (Y2 - abs(X1 - X2) / 2))) cout << "DRAW" << "\n";
            else cout << "BOB" << "\n";
        }
        else {
            if (min(W, Y1 + abs(X1 - X2) / 2) > min(W, Y2 + abs(X1 - X2) / 2)) cout << "DRAW" << "\n";
            else cout << "BOB" << "\n";
        }
    }
    else {
        if (Y1 < Y2) {
            if (min(W, Y2 + abs(X1 - X2) / 2) > min(W, Y1 + 1 + abs(X1 - X2) / 2)) cout << "DRAW" << "\n";
            else cout << "ALICE" << "\n";
        }
        else {
            if (max(1LL, Y2 - abs(X1 - X2) / 2) < max(1LL, Y1 - 1 - abs(X1 - X2) / 2)) cout << "DRAW" << "\n";
            else cout << "ALICE" << "\n";
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