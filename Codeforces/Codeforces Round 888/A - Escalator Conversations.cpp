#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K, H;
    cin >> N >> M >> K >> H;

    vector<int> A(N);
    for (int &i : A) cin >> i;

    int R = 0;
    for (int &i : A) {
        if ((abs(H - i) % K)) continue;
        else if (abs(H - i) / K >= M) continue;
        else if (abs(H - i) == 0) continue;
        else R++;
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