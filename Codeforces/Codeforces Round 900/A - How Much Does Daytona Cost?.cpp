#include <bits/stdc++.h>
using namespace std;
    
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for (int &i : A) cin >> i;

    if (count(begin(A), end(A), K)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}