#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; vector<pair<long long, long long>> A(N);
    for (auto &[i, j] : A) cin >> i >> j; sort(begin(A), end(A));
    
    long long R1, R2 = LLONG_MAX; multiset<long long> B, C;
    for (auto &[i, j] : A) B.insert(j);
    
    R1 = (A[N - 1].first - A[0].first) * (*prev(end(B)) - *begin(B));

    for (int i = 0; i < N - 1; i++) {
        B.erase(B.find(A[i].second)); C.insert(A[i].second);
        if (B.empty()) break;

        long long R3 = (A[i].first - A[0].first) * (*prev(end(C)) - *begin(C));
        long long R4 = (A[N - 1].first - A[i + 1].first) * (*prev(end(B)) - *begin(B));

        R2 = min(R2, R3 + R4);
    }

    auto F = [&] (pair<long long, long long> &x, pair<long long, long long> &y) {
        return x.second < y.second;
    };

    sort(begin(A), end(A), F); B.clear(); C.clear();
    for (auto &[i, j] : A) B.insert(i);

    for (int i = 0; i < N - 1; i++) {
        B.erase(B.find(A[i].first)); C.insert(A[i].first);
        if (B.empty()) break;

        long long R3 = (A[i].second - A[0].second) * (*prev(end(C)) - *begin(C));
        long long R4 = (A[N - 1].second - A[i + 1].second) * (*prev(end(B)) - *begin(B));

        R2 = min(R2, R3 + R4);
    }

    cout << (R1 - R2) << "\n";
    return 0;
}