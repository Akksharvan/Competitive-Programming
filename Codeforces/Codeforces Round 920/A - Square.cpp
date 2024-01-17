#include <bits/stdc++.h>
using namespace std;

void solve () {
    vector<pair<int, int>> A(4);
    for (pair<int, int> &i : A) cin >> i.first >> i.second;

    sort(begin(A), end(A));
    int R = (A[2].first - A[0].first) * (A[2].first - A[0].first);

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