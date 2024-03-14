#include <bits/stdc++.h>
using namespace std;

long long F (pair<long long, long long> &X, long long N) { return (X.first * (X.second + 1) * (N - X.second)); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N; cin >> N; vector<pair<long long, long long>> A(N);
    for (long long i = 0; i < N; i++) { cin >> A[i].first; A[i].second = i; }

    vector<long long> B(N); for (auto &i : B) cin >> i;
    sort(begin(A), end(A), [N] (auto &X, auto &Y) { return F(X, N) < F(Y, N); });

    sort(rbegin(B), rend(B)); long long R = 0;
    for (long long i = 0; i < N; i++) R += F(A[i], N) * B[i];

    cout << R << "\n";
    return 0;
}