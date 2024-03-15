#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q, R = 0; cin >> N >> Q;

    vector<int> A(N); for (auto &i : A) cin >> i;
    map<int, int> B; for (int i = 0; i < N; i++) B[A[i]] = max(i, B[A[i]]);

    for (int i = 0; i < N; i++) {
        map<int, int> C; int j = B[A[i]];
        for (int k = i; k <= j; k++) j = max(j, B[A[k]]), C[A[k]]++;

        int S = INT_MAX;
        for (auto &[k, l] : C) S = min(S, (j - i + 1) - l);

        R += S; i = j;
    }

    cout << R << "\n";
    return 0;
}