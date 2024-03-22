#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R = 0; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        for (int j = 0; j < N; j++) A[i][j] = (S[j] == '1');
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (!A[i][j]) continue; R++;
            for (int k = 0; k <= i; k++) for (int l = 0; l <= j; l++) A[k][l] ^= 1;
        }
    }

    cout << R << "\n";
    return 0;
}