#include <bits/stdc++.h>
using namespace std;

int choi (char c) { return (int) (c - '0'); }

void solve() {
    string S; cin >> S;
    vector<int> A(size(S) + 1);

    reverse(begin(S), end(S));
    for (int i = 0; i < size(S); i++) A[i] = choi(S[i]);

    int K = 0;
    for (int i = 1; i < size(A); i++) {
        if (A[i - 1] >= 5) {
            if (A[i] == 9) {
                while ((i + 1) < size(A) && A[i + 1] == 9) i++;
                i++; A[i]++;
            }
            else A[i] += 1;
            K = max(K, i);
        }
    }

    if (A[size(A) - 1] == 0) A.pop_back();

    for (int i = size(A) - 1; i >= K; i--) cout << A[i];
    for (int i = K - 1; i >= 0; i--) cout << 0;

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}