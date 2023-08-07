#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    int R = 0;
    for (int &i : A) R += (i % 2);

    if (!(R % 2)) cout << "YES" << "\n";
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