#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K; cin >> N >> K;
    vector<set<int>> A(N); vector<int> B(N);

    while (K--) {
        vector<int> C(N); for (auto &i : C) cin >> i;
        for (int i = 2; i < N; i++) A[C[i - 1] - 1].insert(C[i] - 1);
    }

    for (int i = 0; i < N; i++) for (auto j : A[i]) B[j]++;
    queue<int> Q; for (int i = 0; i < N; i++) if (!B[i]) Q.push(i);
    
    vector<int> T; while (!Q.empty()) {
        int X = Q.front(); Q.pop(); T.push_back(X);
        for (auto i : A[X]) { B[i]--; if (!B[i]) Q.push(i); }
    }

    if (size(T) == N) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}