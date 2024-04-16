#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N; cin >> N;
    vector<long long> A(2 * N); for (auto &i : A) cin >> i;

    map<long long, long long> B;
    for (auto &i : A) B[i]++; A.clear();

    for (auto &[i, j] : B) {
        if (j != 2) { cout << "NO" << "\n"; return; }
        else A.push_back(i);
    }

    long long S = 0, R = 0;
    reverse(begin(A), end(A));

    for (long long i = 0; i < N; i++) {
        if ((A[i] - S) % (2 * (N - i))) { cout << "NO" << "\n"; return; }
        R = (A[i] - S) / (2 * (N - i)); S += 2 * R;
    }

    if (R <= 0) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}