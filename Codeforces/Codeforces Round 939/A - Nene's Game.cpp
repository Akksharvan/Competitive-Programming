#include <bits/stdc++.h>
using namespace std;

void solve () {
    int K, Q; cin >> K >> Q;
    vector<int> A(K); for (auto &i : A) cin >> i;

    while (Q--) {
        int N; cin >> N;
        cout << min(A.front() - 1, N) << " ";
    }

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}