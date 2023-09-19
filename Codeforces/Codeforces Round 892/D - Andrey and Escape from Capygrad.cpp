#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++) {
        int X; cin >> A[i].first;
        cin >> X >> X >> A[i].second;
    }

    int Q; cin >> Q; vector<int> R1(N), R2(Q);
    vector<int> B(Q); for (int &i : B) cin >> i;

    multiset<int> C; priority_queue<array<int, 3>> D;
    for (int i = 0; i < Q; i++) D.push({B[i], 1, i});

    for (int i = 0; i < N; i++) {
        D.push({A[i].first, 0, i});
        D.push({A[i].second, 2, i});
    }

    while (!D.empty()) {
        array<int, 3> E = D.top(); D.pop();
        if (E[1] == 0) C.erase(C.find(R1[E[2]]));
        
        if (E[1] == 2) {
            if (C.empty()) R1[E[2]] = E[0], C.insert(E[0]);
            else R1[E[2]] = *prev(end(C)), C.insert(*prev(end(C)));
        }

        if (E[1] == 1) {
            if (C.empty()) R2[E[2]] = E[0];
            else R2[E[2]] = *prev(end(C));
        }
    }

    for (int &i : R2) cout << i << " ";
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}