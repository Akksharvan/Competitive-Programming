#include <bits/stdc++.h>
using namespace std;

vector<int> A(1e7 + 1);
vector<int> B;

void solve() {
    long long C, D;
    cin >> C >> D;

    if (D <= 3) { cout << -1 << "\n"; return; }
    else if (C == D && A[D] == D) { cout << -1 << "\n"; return; }

    if (C == D) {
        long long E = C / A[C];
        cout << (E / 2) * A[C] << " " << (E - (E / 2)) * A[C] << "\n";
    }
    else if (D % 2) cout << (D - 1) / 2 << " " << (D - 1) / 2 << "\n";
    else cout << D / 2 << " " << D / 2 << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= 1e7; i++) {
        if (A[i] == 0) A[i] = i, B.push_back(i);

        for (int j = 0; i * B[j] <= 1e7; ++j) {
            A[i * B[j]] = B[j];
            if (B[j] == A[i]) break;
        }
    }

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}