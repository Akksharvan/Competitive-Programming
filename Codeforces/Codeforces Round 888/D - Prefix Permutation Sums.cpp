#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N; cin >> N;
    vector<long long> A(N - 1); for (long long &i : A) cin >> i;

    map<long long, int> B; B[A[0]]++;
    for (int i = 1; i < N - 1; i++) B[A[i] - A[i - 1]]++;

    vector<long long> C;
    for (int i = 1; i <= N; i++) {
        if (B[i]) continue;
        C.push_back(i);
    }

    vector<long long> D;
    for (const pair<long long, int> &i : B) {
        if (i.second > 1) D.push_back(i.first);
        else if (i.first > N) D.push_back(i.first);
    }

    if (size(C) == 1 && size(D) != 0) { cout << "NO" << "\n"; return; }
    if (size(C) > 2) { cout << "NO" << "\n"; return; }

    if (size(C) == 2) {
        if (size(D) != 1) { cout << "NO" << "\n"; return; }
        if (C[0] + C[1] != D[0]) { cout << "NO" << "\n"; return; }
    }

    cout << "YES" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T; cin >> T;
    while (T--) solve();

    return 0;
}