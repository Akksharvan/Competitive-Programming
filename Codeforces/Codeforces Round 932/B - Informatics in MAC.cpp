#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N; vector<int> A(N);
    for (auto &i : A) cin >> i;

    map<int, int> B; for (auto &i : A) B[i]++;
    int R = -1; for (int i = 0; i < N; i++) {
        if (B[i] == 1) { cout << -1 << "\n"; return; }
        else if (!B[i]) break; else R++;
    }

    if (R == -1) {
        cout << 2 << "\n"; cout << 1 << " " << 1 << "\n";
        cout << 2 << " " << N << "\n"; return;
    }

    set<int> C; for (int i = 0; i < N; i++) {
        if (A[i] <= R) C.insert(A[i]);
        if (size(C) == R + 1) {
            set<int> D; for (int j = i + 1; j < N; j++) if (A[j] <= R) D.insert(A[j]);
            if (size(D) <= R) { cout << -1 << "\n"; return; }
            else {
                cout << 2 << "\n" << 1 << " " << (i + 1) << "\n";
                cout << (i + 2) << " " << N << "\n"; return;
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