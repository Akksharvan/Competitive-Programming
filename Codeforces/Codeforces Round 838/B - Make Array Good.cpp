#include <bits/stdc++.h>
using namespace std;

long long F (long long A) {
    for (long long b = 32; b >= 0; b--) {
        if (!((1 << b) & A)) continue;
        return b;
    }
}

void solve() {
    long long N; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    vector<pair<long long, long long>> R;
    for (long long i = 0; i < N; i++) R.push_back({(i + 1),  (1 << F(A[i]) + 1) - A[i]});

    cout << size(R) << "\n";
    for (pair<long long, long long> &i : R) cout << i.first << " " << i.second << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}