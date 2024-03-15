#include <bits/stdc++.h>
using namespace std;

set<long long> F (vector<long long> &A, long long X) {
    set<long long> B;
    for (int i = 1; i < size(A); i++) B.insert(A[i] + X);
    

    return B;
}

bool G (vector<long long> &A, set<long long> &B) {
    for (auto &i : A) if (!B.count(i)) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long K, N; cin >> K >> N;

    vector<long long> A(K); for (auto &i : A) cin >> i;
    vector<long long> B(N); for (auto &i : B) cin >> i;

    vector<long long> DP(K + 1); set<long long> C;
    for (int i = 1; i <= K; i++) DP[i] = DP[i - 1] + A[i - 1];

    for (int i = 1; i <= K; i++) C.insert(B[0] - DP[i]);
    long long R = size(C); for (auto &i : C) { set<long long> D = F(DP, i); if (!G(B, D)) R--; }

    cout << R << "\n";
    return 0;
}