#include <bits/stdc++.h>
using namespace std;

array<int, (int) 1e6 + 1> S;

map<int, int> F (int X) {
    map<int, int> A;
    while (X != 1) A[S[X]]++, X /= S[X];

    return A;
}
    
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(1, N);

    while (Q--) {
        int T; cin >> T;
        if (T == 2) { A.resize(1, N); continue; }

        int X; cin >> X;
        A.push_back(X);

        map<int, int> B;
        for (int i = 0; i < size(A); i++) {
            map<int, int> C = F(A[i]);
            for (const pair<int, int> &i : C) B[i.first] += i.second;
        }

        long long R1 = 1, R2 = 1;
        for (const pair<int, int> &i : B) R1 *= (i.second + 1);

        for (int &i : A) R2 *= i, R2 %= R1;
        cout << (!R2 ? "YES" : "NO") << "\n";
    }

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= 1e6; i++) {
        if (S[i]) continue;
        for (int j = i; j <= 1e6; j += i) S[j] = i;
    }

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}