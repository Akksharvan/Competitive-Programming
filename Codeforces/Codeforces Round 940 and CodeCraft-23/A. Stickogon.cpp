#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N; map<int, int> A;
    while (N--) { int x; cin >> x; A[x]++; }

    int R = 0;
    for (auto &[i, j] : A) R += (j / 3);

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