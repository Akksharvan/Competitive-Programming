#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N; cin >> N;
    long long R = 0, I = 1;
    
    while (!(N % I)) {
        R++; I += 1;
    }
    
    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}