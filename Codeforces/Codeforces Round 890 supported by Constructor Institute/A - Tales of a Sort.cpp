#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;

    int R = 0, B = 0;
    for (int &i : A) {
        if (i < B) R = B;
        else B = max(B, i);
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