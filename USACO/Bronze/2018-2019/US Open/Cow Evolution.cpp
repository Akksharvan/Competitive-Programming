#include <bits/stdc++.h>
using namespace std;

bool F (set<int> &A, set<int> &B) {
    for (auto &i : A) if (!B.count(i)) return 0;
    return 1;
}

bool G (set<int> &A, set<int> &B) {
    for (auto &i : A) if (B.count(i)) return 1;
    return 0;
}

int main() {
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; map<string, set<int>> A;
    while (N--) { int K; string S; cin >> K; while (K--) { cin >> S; A[S].insert(N); } }

    for (auto &[i, j] : A) {
        for (auto &[k, l] : A) {
            if (i == k || F(j, l) || F(l, j)) continue;
            if (G(j, l)) { cout << "no" << "\n"; return 0; }
        }
    }

    cout << "yes" << "\n";
    return 0;
}