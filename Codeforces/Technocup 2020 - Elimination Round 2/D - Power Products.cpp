#include <bits/stdc++.h>
using namespace std;

array<long long, (long long) 2e5 + 1> S;
map<map<long long, long long>, long long> B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, K, M = 0; long long R = 0; cin >> N >> K;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    for (long long i = 2; i <= 2e5; i++) {
        if (S[i]) continue;
        for (long long j = i; j <= 2e5; j += i) S[j] = i;
    }

    M = count(begin(A), end(A), 1);
    R += ((M - 1LL) * M) / 2;

    for (long long &i : A) {
        if (i == 1) continue;

        map<long long, long long> C; while (i != 1) C[S[i]]++, i /= S[i];
        map<long long, long long> D, F; for (const pair<long long, long long> &j : C) if (j.second % K) D[j.first] = K - (j.second % K), F[j.first] = j.second % K;

        if (F.empty()) R += M;
        R += B[D], B[F]++;
    }

    cout << R << "\n";
    return 0;
}