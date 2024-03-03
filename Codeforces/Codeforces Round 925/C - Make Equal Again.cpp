#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (auto &i : A) cin >> i;

    if (N == 2) {
        if (A.front() == A.back()) cout << 0 << "\n";
        else cout << 1 << "\n"; return;
    }

    int I = 1, J = N - 2;

    while (I < N && A[I] == A[I - 1]) I++;
    while (J >= 0 && A[J] == A[J + 1]) J--;

    if (A.front() == A.back()) cout << max(0, J - I + 1) << "\n";
    else cout << min(N - I, J + 1) << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}