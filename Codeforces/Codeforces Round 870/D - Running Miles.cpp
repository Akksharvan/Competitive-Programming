#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N;
    vector<int> A(N); for (auto &i : A) cin >> i;

    vector<int> DP1(N), DP2(N);
    for (int i = 0; i < N; i++) DP1[i] = A[i] + i, DP2[i] = A[i] - i;

    for (int i = 1; i < N; i++) DP1[i] = max(DP1[i], DP1[i - 1]);
    for (int i = N - 2; i >= 0; i--) DP2[i] = max(DP2[i], DP2[i + 1]);

    int R = 0;
    for (int i = 1; i < N - 1; i++) R = max(R, A[i] + DP1[i - 1] + DP2[i + 1]);

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