#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for (int &i : A) cin >> i;

    sort(begin(A), end(A));

    int R = 1, S = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] - A[i - 1] <= K) S++;
        else { R = max(R, S); S = 1; }
    }

    R = max(R, S);

    cout << (N - R) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}