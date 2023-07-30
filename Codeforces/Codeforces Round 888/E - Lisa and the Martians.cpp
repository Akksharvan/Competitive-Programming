#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N); for (int &i : A) cin >> i;

    map<int, vector<int>> B;
    for (int i = 0; i < N; i++) B[A[i]].push_back(i);

    sort(begin(A), end(A));
    int X = INT_MAX, Y = - 1, Z = -1;

    for (int i = 1; i < N; i++) {
        if ((A[i] ^ A[i - 1]) >= X) continue;
        X = (A[i] ^ A[i - 1]); Y = (i - 1); Z = i;
    }

    X = (((1 << K) - 1) - (A[Y] ^ A[Z])); X = ((X ^ A[Y]) & (X ^ A[Z]));
    Y = B[A[Y]][0]; Z = B[A[Z]][size(B[A[Z]]) - 1];
    
    if (Y > Z) swap(Y, Z);
    cout << (Y + 1) << " " << (Z + 1) << " " << X << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}