#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
bool foo (char c) { return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); }

void solve() {
    int  N, K; string S;
    cin >> N >> K >> S;

    int A = 0; vector<int> B;
    for (int i = 0; i < N; i++) { if (foo(S[i])) { A++; if (!(A % K)) { B.push_back(i); } } }

    int C = 0; vector<int> D;
    for (int i = N - 1; i >= 0; i--) { if (foo(S[i])) { C++; if (!(C % K)) { D.push_back(i); } } }

    reverse(begin(D), end(D));

    long long R = 1; for (int i = 0; i < size(B) - 1; i++) { R *= (long long) (D[i + 1] - B[i]); R %= MOD; }
    cout << (R % MOD) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}