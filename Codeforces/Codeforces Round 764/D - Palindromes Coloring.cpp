#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N, K; cin >> N >> K; string S; cin >> S;
    vector<int> A(26); for (auto &i : S) A[i - 'a']++;

    int R1 = 0, R2 = 0; for (int i = 0; i < 26; i++) R1 += (A[i] / 2), R2 += A[i] % 2;
    cout << (2 * (R1 / K)) + min(1, (R2 + (2 * (R1 % K))) / K) << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}