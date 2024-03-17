#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R = 0; cin >> N;
    vector<int> A(N); for (auto &i : A) cin >> i;

    sort(begin(A), end(A)); map<int, int> B, C;
    B[0] = 1, B[N - 1] = N - 2, C[1]++, C[N - 2]++;

    for (int i = 1; i < N - 1; i++) {
        if (A[i] - A[i - 1] <= A[i + 1] - A[i]) B[i] = i - 1, C[i - 1]++;
        else if (A[i] - A[i - 1] > A[i + 1] - A[i]) B[i] = i + 1, C[i + 1]++;
    }

    for (int i = 0; i < N; i++) {
        if (C[i] == 0) R++;
        if (i < B[i] && B[B[i]] == i && C[i] == 1 && C[B[i]] == 1) R++;
    }

    cout << R << "\n";
    return 0;
}