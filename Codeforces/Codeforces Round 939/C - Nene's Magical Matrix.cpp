#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, R1 = 0; cin >> N;
    vector<vector<int>> R2; long long R3 = (N * (N + 1)) / 2;

    for (int i = 1; i <= N; i++) {
        vector<int> A; A.push_back(1); A.push_back(i);
        for (int j = 1; j <= N; j++) A.push_back(j);

        vector<int> B; B.push_back(2); B.push_back(i);
        for (int j = 1; j <= N; j++) B.push_back(j);

        R2.push_back(A); R2.push_back(B);
    }

    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) R1 += max(i, j);
    reverse(begin(R2), end(R2));

    cout << R1 << " " << ((int) size(R2)) << "\n";
    for (auto &i : R2) { for (auto &j : i) cout << j << " "; cout << "\n"; }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}