#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> A(N); for (int &i : A) cin >> i;

    map<pair<int, int>, int> B; long long R = 0;
    for (int i = N - 1; i >= 0; i--) {
        R += B[make_pair(A[i] % X, A[i] % Y)];
        B[make_pair((((X - A[i]) % X) + X) % X, (Y + A[i]) % Y)]++;
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