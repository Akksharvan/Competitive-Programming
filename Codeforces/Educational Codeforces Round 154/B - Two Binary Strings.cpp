#include <bits/stdc++.h>
using namespace std;

void solve() {
    string A, B;
    cin >> A >> B;

    for (int i = 0; i < size(A); i++) {
        if (A[i] == '0' && B[i] == '0') {
            for (int j = i + 1; j < size(A); j++) {
                if (A[j] != B[j]) break;
                if (A[j] == '0') continue;

                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}