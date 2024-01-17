#include <bits/stdc++.h>
using namespace std;

int F (int L, int H, int X, vector<int> &R) {
    while (L < H) {
        int M = L + (H - L) / 2;
        if (R[M] >= X) H = M;
        else L = M + 1;
    }

    return L;
}
    
void solve() {
    int N, K; string S;
    cin >> N >> K >> S;

    vector<int> L(K); for (int &i : L) { cin >> i; i--; }
    vector<int> R(K); for (int &i : R) { cin >> i; i--; }

    int Q; cin >> Q; vector<vector<int>> A(K);
    for (int i = 0; i < K; i++) A[i].resize(R[i] - L[i] + 1);

    while (Q--) {
        int X; cin >> X; X--;
        int I = F(0, K - 1, X, R);

        int D = min(X, L[I] + R[I] - X) - L[I];
        int E = max(X, L[I] + R[I] - X) - L[I];

        A[I][D]++;
        if (E + 1 < size(A[I])) A[I][E + 1]--;
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < size(A[i]); j++) {
            if (j == 0) continue;
            else A[i][j] += A[i][j - 1];
        }
    }

    string B;

    for (int i = 0; i < K; i++) {
        vector<char> C;
        for (int j = L[i]; j <= R[i]; j++) C.push_back(S[j]);

        for (int j = 0; j < size(C) / 2; j++) {
            if (!(A[i][j] % 2)) continue;
            else swap(C[j], C[size(C) - j - 1]);
        }

        for (char &c : C) B += c;
    }

    cout << B << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}