#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, R = 0;
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        int A = i, B = N, k = 2;
        while (A <= B && A >= 0) {
            swap(A, B); A = (A - B);
            if (A > B || A < 0) break;
            if (++k == K) { R++; break; }
        }
    }

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T; cin >> T;
    while (T--) solve();

    return 0;
}