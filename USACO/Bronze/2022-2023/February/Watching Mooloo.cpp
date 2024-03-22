#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, K, R = 0; cin >> N >> K;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    for (long long i = 0; i < N; i++) {
        R += K + 1; if (i + 1 >= N || A[i + 1] - A[i] > K + 1) continue;
        while (i + 1 < N && A[i + 1] - A[i] <= K + 1) R += A[i + 1] - A[i], i++;
    }

    cout << R << "\n";
    return 0;
}