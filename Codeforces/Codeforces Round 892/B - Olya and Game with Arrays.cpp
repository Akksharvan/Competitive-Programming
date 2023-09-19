#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<pair<long long, long long>> A(N);

    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        vector<long long> B(M);

        for (long long &i : B) cin >> i;
        sort(begin(B), end(B));

        A[i].first = B[0];
        A[i].second = B[1];
    }

    sort(begin(A), end(A));

    long long T = A[0].first;
    for (int i = 1; i < N; i++) T += A[i].second;

    long long R = T;
    for (int i = 1; i < N; i++) R = max(R, T + A[0].second - A[i].second);

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