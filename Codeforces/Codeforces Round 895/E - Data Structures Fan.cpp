#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    string S; cin >> S;
    long long X = 0, Y = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == '0') X ^= A[i];
        else Y ^= A[i];

        if (i == 0) continue;
        else A[i] ^= A[i - 1];
    }

    int Q; cin >> Q;
    while (Q--) {
        int T; cin >> T;
        if (T == 1) {
            int L, R; cin >> L >> R;
            if (L == 1) X ^= A[R - 1], Y ^= A[R - 1];
            else X ^= (A[R - 1] ^ A[L - 2]), Y ^= (A[R - 1] ^ A[L - 2]);
        }
        else {
            int B; cin >> B;
            if (B == 0) cout << X << " ";
            else cout << Y << " ";
        }
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