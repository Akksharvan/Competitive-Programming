#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    vector<string> B(N + 1);
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 50; j++) {
            B[i] += 'a';
        }
    }
    
    for (int i = 1; i <= N; i++) {
        B[i] = B[i - 1];
        B[i][A[i - 1]] = (char) ((((int) (B[i][A[i - 1]] - 'a') + 1)) % 26 + 97);
    }

    for (string &i : B) cout << i << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}