#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R1 = 1, R2 = 1; cin >> N;
    vector<int> A(N); for (auto &i : A) cin >> i;
    
    for (int i = N - 1; i > 0; i--) {
        if (A[i] != -1) {
            for (int j = i; j >= i - A[i]; j--) {
                if (A[j] == -1 || A[j] == A[i] - (i - j)) continue;
                else { cout << -1 << "\n"; return 0; }
            }

            i -= A[i]; R1++; R2++;
        }
        else {
            int j = i; while (j > 0 && A[j] == -1) j--;
            R2 += (i - j); i = j + 1;
        }
    }

    for (int i = 1; i < N; i++) if (i == A[i]) { R1--, R2--; break; }

    cout << R1 << " " << R2 << "\n";
    return 0;
}