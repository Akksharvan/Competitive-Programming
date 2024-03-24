#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; vector<int> A(N + 1);
    for (int i = 0; i < N - 1; i++) { int U, V; cin >> U >> V; A[U]++; A[V]++; }

    int R = 0; for (int i = 1; i <= N; i++) R = max(R, A[i]);
    cout << R + 1 << "\n";

    return 0;
}