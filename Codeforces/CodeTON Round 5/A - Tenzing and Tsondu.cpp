#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, M; cin >> N >> M;
    vector<long long> A(N); for (long long &i : A) cin >> i;
    vector<long long> B(M); for (long long &i : B) cin >> i;

    long long a = accumulate(begin(A), end(A), 0LL);
    long long b = accumulate(begin(B), end(B), 0LL);

    if (a > b) cout << "Tsondu" << "\n";
    if (a < b) cout << "Tenzing" << "\n";
    if (a == b) cout << "Draw" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}