#include <bits/stdc++.h>
using namespace std;

void solve () {
    string X, Y; cin >> X >> Y;
    int N = size(X); string A, B; bool C = 0;

    for (int i = 0; i < N; i++) {
        if (X[i] == Y[i]) A += X[i], B += Y[i];
        else if (!C) A += max(X[i], Y[i]), B += min(X[i], Y[i]), C = !C;
        else A += min(X[i], Y[i]), B += max(X[i], Y[i]);
    }

    cout << A << "\n" << B << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}