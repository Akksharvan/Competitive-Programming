#include <bits/stdc++.h>
using namespace std;

inline int F (int X) {
    int R = 0; while (X > 0) R ++, X /= 10;
    return R;
}

inline int G (int X) {
    int R = 0; while (!(X % 10)) R++, X /= 10;
    return R;
}

void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N); for (auto &i : A) cin >> i;

    if (N == 1) {
        cout << ((F(A.front()) - G(A.front())) <= M ? "Anna" : "Sasha") << "\n";
        return;
    }

    int R1 = 0; vector<int> R2;
    for (auto &i : A) R1 += F(i), R2.push_back(G(i));

    sort(rbegin(R2), rend(R2));
    for (int i = 0; i < N; i += 2) R1 -= R2[i];

    cout << (R1 <= M ? "Anna" : "Sasha") << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}