#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for (int &i : A) cin >> i;
    for (int &i : B) cin >> i;

    vector<pair<int, int>> C;
    for (int i = 0; i < N; i++) C.push_back({A[i] - B[i], (i + 1)});

    sort(rbegin(C), rend(C));
    vector<int> D;

    for (pair<int, int> &i : C) {
        if (i.first != C[0].first) continue;
        else D.push_back(i.second);
    }

    sort(begin(D), end(D));
    cout << size(D) << "\n";

    for (int &i : D) cout << i << " ";
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}