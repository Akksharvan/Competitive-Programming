#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    int R1 = 0;
    int R2 = 0;
    int S1 = 0;
    int S2 = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > 0) R1++;
        else R1 = 0;

        if (B[i] > 0) R2++;
        else R2 = 0;

        S1 = max(S1, R1);
        S2 = max(S2, R2);
    }

    if (S1 > S2) cout << "Om" << "\n";
    else if (S2 > S1) cout << "Addy" << "\n";
    else cout << "Draw" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}