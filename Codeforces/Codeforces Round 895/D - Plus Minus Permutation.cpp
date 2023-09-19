#include <bits/stdc++.h>
using namespace std;

long long F (long long A) { return ((A * (A + 1)) / 2); }

void solve() {
    long long N, X, Y;
    cin >> N >> X >> Y;

    long long A = (N / X) - (N / lcm(X, Y));
    long long B = (N / Y) - (N / lcm(X, Y));

    long long R = (A ? (F(N) - F(N - A)) : 0) - F(B);
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