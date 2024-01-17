#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long N, M, R = 0, I = 0, J = 0; cin >> N >> M;

    vector<long long> A(N); for (long long &i : A) cin >> i;
    vector<long long> C(M); for (long long &i : C) cin >> i;

    sort(begin(A), end(A));
    sort(rbegin(C), rend(C));

    // for (long long &i : A) cerr << i << " "; cerr << "\n";
    // for (long long &i : C) cerr << i << " "; cerr << "\n";

    while (I < N && abs(A[I] - C[J]) >= abs(A[I] - C[(M - (N - I))])) {
        R += abs(A[I] - C[J]);
        I++; J++;
    }

    // cerr << I << " " << M - (N - I) << "\n";
    J = M - 1;

    while (I < N) {
        R += abs(A[I] - C[J]);
        I++; J--;
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