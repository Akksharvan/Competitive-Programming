#include <bits/stdc++.h>
using namespace std;

long long F (vector<long long> &A, int N) {
    vector<long long> B = A;
    reverse(begin(B) + N, end(B));

    long long R = 0, S = 0;
    for (long long i = 0; i < size(B); i++) {
        R += ((i + 1) * B[i]);
        S = max(S, ((i + 1) * B[i]));
    }

    return (R - S);
}

void solve() {
    long long N, R = 0; cin >> N;
    vector<long long> A;

    for (int i = 1; i <= N; i++) A.push_back(i);
    for (int i = 0; i < N; i++) R = max(R, F(A, i));

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