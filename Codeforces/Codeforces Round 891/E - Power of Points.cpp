#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N; cin >> N;
    vector<pair<long long, long long>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(begin(A), end(A));
    vector<long long> R(N);

    long long P = 0;
    for (int i = 0; i < N; i++) P += (A[i].first - A[0].first + 1);

    R[A[0].second] = P;
    for (int i = 1; i < N; i++) {
        if (A[i].first == A[i - 1].first) {
            R[A[i].second] = P;
            continue;
        }

        P += (i * (A[i].first - A[i - 1].first));
        P -= ((N - i) * (A[i].first - A[i - 1].first));
        
        R[A[i].second] = P;
    }

    for (long long &i : R) cout << i << " ";
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}