#include <bits/stdc++.h>
using namespace std;

vector<int> P;
array<int, (int) 2e7 + 1> S;

void solve () {
    int C, D, X; cin >> C >> D >> X;

    int Y = gcd(C, D); if (X % Y) { cout << 0 << "\n"; return; }
    else { C /= Y, D /= Y, X /= Y; }

    vector<int> F; long long R = 0; for (int i = 1; i * i <= X; i++) {
        if ((X % i)) continue; F.push_back(i);
        if (i != (X / i)) F.push_back(X / i);
    }

    for (int &i : F) {
        if ((i + D) % C) continue;
        int K = (i + D) / C; long long B = 0;

        while (K != 1) { B++; Y = S[K]; while (S[K] == Y) K /= Y; }
        R += (1 << B);
    }

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= 2e7; i++) {
        if (!S[i]) S[i] = i, P.push_back(i);
        for (int j = 0; i * P[j] <= 2e7; j++) { S[i * P[j]] = P[j]; if (P[j] == S[i]) { break; } }
    }

    int T; cin >> T;
    while (T--) solve();

    return 0;
}