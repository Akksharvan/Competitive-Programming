#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N; vector<pair<int, int>> A(N);
    for (auto &i : A) cin >> i.first; for (auto &i : A) cin >> i.second;

    sort(begin(A), end(A));

    for (auto &i : A) cout << i.first << " "; cout << "\n";
    for (auto &i : A) cout << i.second << " "; cout << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}