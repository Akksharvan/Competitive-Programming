#include <bits/stdc++.h>
using namespace std;

int F (int L, int H, long long C, vector<pair<long long, long long>> &A) {
    while (L < H) {
        int M = L + (H - L + 1) / 2;
        if (C >= A[M].first) L = M;
        else H = M - 1;
    }

    return L;
}

void solve() {
    long long N, C;
    cin >> N >> C;

    vector<long long> A(N);
    for (long long &i : A) cin >> i;

    vector<pair<long long, long long>> B(N);
    for (long long i = 0; i < N; i++) { B[i].first = A[i] + min((i + 1), (N - i)); B[i].second = i; }

    sort(begin(B), end(B));
    for (int i = 1; i < N; i++) B[i].first += B[i - 1].first;

    vector<long long> D(N);
    for (pair<long long, long long> &i : B) D[i.second] = i.first;

    int R = -1;
    for (long long i = 0; i < N; i++) {
        if ((C - (A[i] + (i + 1)) >= D[i])) R = max(R, F(-1, N - 1, C - (i + 1) + min((i + 1), (N - i)), B));
        else if (C - (A[i] + (i + 1)) >= 0) R = max(R, F(-1, N - 1, C - (A[i] + (i + 1)), B) + 1);
    }

    cout << (R + 1) << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}