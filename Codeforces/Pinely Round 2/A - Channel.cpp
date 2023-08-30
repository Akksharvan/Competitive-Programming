#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, A, Q;
    cin >> N >> A >> Q;

    vector<int> B(Q);
    for (int &i : B) {
        char c; cin >> c;
        i = ((c == '+') ? (1) : (-1));
    }

    int C = A; int D = A, E = A;
    for (int &i : B) {
        if (i == 1) E += 1, D += 1;
        else E -= 1; C = max(C, E);
    }

    if (C >= N) cout << "YES" << "\n";
    else if (D >= N) cout << "MAYBE" << "\n";
    else cout << "NO" << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}