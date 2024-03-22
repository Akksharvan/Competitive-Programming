#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    vector<int> A(N); for (auto &i : A) cin >> i;
    vector<int> B = A; sort(begin(B), end(B));

    int C = 0; for (int i = 0; i < N; i++) C += (A[i] != B[i]);
    cout << (C - 1) << "\n";

    return 0;
}