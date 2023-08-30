#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;

    vector<vector<char>> A(N, vector<char> (M));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> A[i][j];

    vector<int> B(N);
    vector<int> C(M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '.') continue;
            else if (A[i][j] == 'U') {
                if (B[i]) {
                    A[i][j] = 'W'; A[i + 1][j] = 'B';
                    B[i]--; B[i + 1]++;
                }
                else {
                    A[i][j] = 'B'; A[i + 1][j] = 'W';
                    B[i]++; B[i + 1]--;
                }
            }
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (A[i][j] == '.') continue;
            else if (A[i][j] == 'L') {
                if (C[j]) {
                    A[i][j] = 'W'; A[i][j + 1] = 'B';
                    C[j]--; C[j + 1]++;
                }
                else {
                    A[i][j] = 'B'; A[i][j + 1] = 'W';
                    C[j]++; C[j + 1]--;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!B[i]) continue;
        cout << -1 << "\n"; return;
    }

    for (int i = 0; i < M; i++) {
        if (!C[i]) continue;
        cout << -1 << "\n"; return;
    }

    for (vector<char> &i : A) {
        for (char &j : i) cout << j;
        cout << "\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}