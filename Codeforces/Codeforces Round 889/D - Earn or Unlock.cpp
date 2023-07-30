#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, R = 0; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    vector<long long> B = A;
    for (int i = 1; i < N; i++) B[i] += B[i - 1];

    bitset<(int) 2e5 + 5> DP; DP[0] = 1;
    for (int i = 0; i < N; i++) {
        DP |= (DP << A[i]);
        if (DP[i]) R = max(R, B[i] - i); DP[i] = 0;
    }

    for (int i = (N - 1); i <= (2 * N); i++) {
        if (!DP[i]) continue;
        R = max(R, B[N - 1] - i); break;
    }

    cout << R << "\n";
    return 0;
}