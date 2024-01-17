#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, K, D, R1 = 0; cin >> N >> K >> D;

    vector<int> A(N); for (int &i : A) cin >> i;
    vector<int> B(K); for (int &i : B) cin >> i;

    for (int i = 1; i <= min(D, 2 * N); i++) {
        int R2 = 0; for (int j = 0; j < N; j++) R2 += (A[j] == j + 1);
        R1 = max(R1, R2 + (D - i) / 2); for (int j = 0; j < N; j++) A[j] += (B[(i - 1) % K] > j);
    }

    cout << R1 << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}