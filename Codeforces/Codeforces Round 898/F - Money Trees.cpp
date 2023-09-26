#include <bits/stdc++.h>
using namespace std;
    
void solve() {
    long long N, K, F = 0; cin >> N >> K;
    vector<long long> A(N), B(N);
    
    for (long long &i : A) cin >> i;
    for (long long &i : B) cin >> i;

    for (int i = 0; i < N;) {
        vector<long long> C; C.push_back(A[i]); i++;
        while (i < N && !(B[i - 1] % B[i])) C.push_back(A[i]), i++;

        long long L = 0, R = 0;
        long long M = size(C), D = 0;

        while (L < M) {
            while (R < M && (D + C[R]) <= K) D += C[R], R++;
            F = max(F, (R - L)); D -= C[L]; L++;
        }
    }
    
    cout << F << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}