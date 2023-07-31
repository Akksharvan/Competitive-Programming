#include <bits/stdc++.h>
using namespace std;

int prime(int x) {
    for (int i = 2; (i * i) < x; i++) {
        if (x % i == 0) return i;
    }

    return -1;
}

void solve() {
    int N; cin >> N;
    int ret = prime(N);

    if (ret == -1) cout << -1 << "\n";
    else cout << 1 << " " << ret << " " << (N / ret) << " " << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) solve();
    
    return 0;
}