#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N;
    vector<int> A(N); for (auto &i : A) cin >> i;

    sort(begin(A), end(A));
    int R = 0; for (int i = 1; i < N; i++) R += A[i] - A[i - 1];

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