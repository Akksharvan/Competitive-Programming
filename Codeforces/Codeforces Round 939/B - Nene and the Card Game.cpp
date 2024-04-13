#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N; vector<int> A(N);
    for (int i = 0; i < N; i++) { int X; cin >> X; X--; A[X]++; }

    int R = count(begin(A), end(A), 2);
    cout << R << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}