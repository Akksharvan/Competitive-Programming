#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++) {
        int X; cin >> X;
        if (A.empty()) { A.push_back(X); continue; }

        if (X != 0 && A[size(A) - 1] != 0) A[size(A) - 1] = max(A[size(A) - 1], X);
        else A.push_back(X);
    }

    N = size(A);
    vector<int> B(N); int R = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] != 2) continue;
        if (!B[i]) { R++; B[i] = 1; }

        if (i == 0) { B[i + 1] = 1; continue; }
        if (i == N - 1) { B[i - 1] = 1; continue; }

        B[i - 1] = 1; B[i + 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != 1) continue;
        if (!B[i]) { R++; B[i] = 1; }

        if (i == 0) { B[i + 1] = 1; continue; }
        if (i == N - 1) { B[i - 1] = 1; continue; }

        if (!B[i - 1]) B[i - 1] = 1;
        else B[i + 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (!B[i]) R++;
    }

    cout << R << "\n";
    return 0;
}