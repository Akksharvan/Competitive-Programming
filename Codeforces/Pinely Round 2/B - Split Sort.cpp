#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A[x] = i;
    }

    int R = 0;
    for (int i = 2; i <= N; i++) if (A[i - 1] > A[i]) R++;

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