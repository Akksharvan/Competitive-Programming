#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, R = INT_MAX; cin >> N; vector<int> A(N); for (auto &i : A) cin >> i;
    if (count(begin(A), end(A), A.front()) == N) { cout << -1 << "\n"; return; }

    vector<int> B(1, -1); for (int i = 0; i < N; i++) if (A[i] != A.front()) B.push_back(i);
    B.push_back(N); N = size(B); for (int i = 1; i < N; i++) R = min(R, B[i] - B[i - 1] - 1);

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