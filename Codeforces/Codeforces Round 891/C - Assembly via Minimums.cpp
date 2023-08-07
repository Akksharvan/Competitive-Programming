#include <bits/stdc++.h>
using namespace std;

void F (map<int, int> &A, vector<int> &B) {
    for (int &i : B) if (A[i] == 0) A.erase(i);
}

void solve() {
    int N; cin >> N;
    vector<int> A((N * (N - 1)) / 2);

    for (int &i : A) cin >> i;
    map<int, int> B; for (int &i : A) B[i]++;

    vector<int> C, D;
    for (const pair<int, int> &i : B) C.push_back(i.first);

    for (int i = N - 1; i > 0; i--) {
        F(B, C); if (C.empty()) continue;
        begin(B) -> second = begin(B) -> second - i;
        D.push_back(begin(B) -> first);
    }

    for (int &i : D) cout << i << " ";
    cout << D[size(D) - 1] << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}