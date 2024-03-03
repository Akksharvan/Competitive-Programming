#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N; vector<long long> A(N);
    for (auto &i : A) cin >> i; long long R = 0;

    sort(begin(A), end(A));
    cout << abs(A[0] - A[N - 1]) + abs(A[N - 1] - A[1]) + abs(A[1] - A[N - 2]) + abs(A[N - 2] - A[0]) << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}