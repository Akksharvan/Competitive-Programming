#include <bits/stdc++.h>
using namespace std;

bool F (pair<long long, long long> &x, pair<long long, long long> &y) { return ((x.first == y.first) ? (x.second > y.second) : (x.first < y.first)); }

void solve() {
    long long N, K; cin >> N >> K;
    vector<pair<long long, long long>> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = (i + 1);

        if (!(A[i].first % K)) A[i].first = K;
        else A[i].first %= K;
    }

    sort(begin(A), end(A), F);
    reverse(begin(A), end(A));

    for (pair<long long, long long> &i : A) cout << i.second << " ";
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}