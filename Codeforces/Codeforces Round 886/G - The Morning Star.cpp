#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N; cin >> N;
    vector<pair<int, int>> A(N);

    for (pair<int, int> &i : A) {
        cin >> i.first;
        cin >> i.second;
    }

    map<int, long long> B, C;
    map<int, long long> D, E;

    for (pair<int, int> &i : A) {
        B[i.first]++;
        C[i.second]++;
        
        D[(-1) * (i.first) + i.second]++;
        E[(1) * (i.first) + i.second]++;
    }

    long long R = 0;
    for (pair<int, int> &i : A) {
        R += (B[i.first] - 1);
        R += (C[i.second] - 1);

        R += (D[(-1) * (i.first) + i.second] - 1);
        R += (E[(1) * (i.first) + i.second] - 1);
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