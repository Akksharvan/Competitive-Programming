#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<pair<int, int>> A(N);

    for (pair<int, int> &i : A) {
        cin >> i.first;
        cin >> i.second;
    }

    int R = -1;
    for (int i = 0; i < N; i++) {
        if (A[i].first <= 10) {
            if (R == -1) R = i;
            else if (A[i].second > A[R].second) R = i;
        }
    }
    
    cout << (R + 1) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}