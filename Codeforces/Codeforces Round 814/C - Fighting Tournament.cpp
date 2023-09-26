#include <bits/stdc++.h>
using namespace std;
    
void solve() {
    int N, Q, R = 0; cin >> N >> Q;
    vector<int> A(N + 1); for (int i = 1; i <= N; i++) cin >> A[i];

    vector<int> B(N + 1), C(N + 1); stack<int> D; D.push(A[1]);
    for (int i = 1; i <= N; i++) B[i] = ((R > A[i]) ? 1 : 0), R = max(R, A[i]);

    for (int i = 2; i <= N; i++) {
        while (!D.empty() && D.top() < A[i]) C[D.top()] = i, D.pop();
        D.push(A[i]);
    }

    while (Q--) {
        int I, K; cin >> I >> K;
        if (I == 1) {
            if (A[I] == N || K < C[A[I]] - 1) cout << K << "\n";
            else cout << (C[A[I]] - 2) << "\n";
        }
        else {
            if (B[I]) cout << 0 << "\n";
            else if (A[I] == N || K < C[A[I]] - 1) cout << max(0, (K - (I - 2))) << "\n";
            else cout << max(0, ((C[A[I]] - 2) - (I - 2))) << "\n";
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}