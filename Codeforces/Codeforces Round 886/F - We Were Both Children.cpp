#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);

    for (int i = 0; i < N; i++) {
        int X; cin >> X;
        if (X <= N) A[X]++;
    }

    vector<int> B(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            B[j] += A[i];
        }
    }

    int R = INT_MIN;
    for (int i = 1; i <= N; i++) R = max(R, B[i]);

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