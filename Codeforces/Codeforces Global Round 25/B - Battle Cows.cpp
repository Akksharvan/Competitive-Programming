#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, I; cin >> N >> I; I--;
    vector<int> A(N); for (auto &i : A) cin >> i;

    int J = 0, R1 = -1, R2 = -1;

    while (J < I) {
        if (A[J] > A[I] && R1 == -1 && R2 == -1) R1 = J;
        else if (A[J] > A[I] && R1 != -1 && R2 == -1) R2 = J; J++;
    }

    if (R1 == -1) {
        J = I; while (I + 1 < N && A[J] > A[I + 1]) I++;
        cout << I << "\n"; return;
    }

    if (R2 == -1) {
        if (R1 == 0) cout << (I - 1) << "\n";
        else cout << max(R1 - 1, I - R1) << "\n";
    }

    if (R2 != -1) {
        if (R1 == 0) cout << (R2 - 1) << "\n";
        else cout << max(R1 - 1, R2 - R1) << "\n";
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