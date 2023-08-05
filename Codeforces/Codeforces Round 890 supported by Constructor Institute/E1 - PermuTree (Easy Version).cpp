#include <bits/stdc++.h>
using namespace std;

long long R = 0;

void F (long long N, vector<long long> &DP, vector<long long> &A) {
    vector<long long> B(size(A));
    for (int i = 0; i < size(A); i++) B[i] = DP[A[i]];

    vector<bool> D(2 * size(DP)); D[0] = 1;
    for (int i = 1; i < size(B); i++) {
        for (int j = size(DP); j >= 0; j--) {
            if (!D[j]) continue;
            D[j + B[i]] = 1;
        }
    }

    long long T = 0;
    for (int i = 0; i < size(DP) + 1; i++) {
        if (!D[i]) continue;
        T = max(T, (i * (DP[N] - i - 1)));
    }

    R += T;
    return;
}

void DFS1 (long long N, vector<long long> &DP, vector<vector<long long>> &A) {
    for (long long &L : A[N]) DFS1(L, DP, A);
    for (long long &L : A[N]) DP[N] += DP[L];
}

void DFS2 (long long N, vector<long long> &DP, vector<vector<long long>> &A) {
    if (size(A[N]) == 0) return;
    else F(N, DP, A[N]);

    for (long long &L : A[N]) DFS2(L, DP, A);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N; cin >> N;
    vector<vector<long long>> A(N);

    for (long long i = 1; i < N; i++) {
        long long X; cin >> X;
        A[--X].push_back(i);
    }

    vector<long long> DP(N, 1);
    DFS1(0, DP, A);

    for (long long i = 0; i < N; i++) {
        sort(begin(A[i]), end(A[i]), [DP](long long &x, long long &y) {
            return DP[x] > DP[y];
        });
    }
    
    DFS2(0, DP, A);
    cout << R << "\n";
    
    return 0;
}