#include <bits/stdc++.h>
using namespace std;

bool F (long long S, long long X, long long K) {
    if (((S * (S - 1)) / 2) - ((X * (X + 1)) / 2) < K) return 1;
    else return 0;
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    long long K, N; cin >> K >> N;
    vector<long long> A(N); for (auto &i : A) cin >> i;

    for (auto &i : A) {
        long long D = K, S = 0, T = 0;
        
        while (D > 0) {
            if (F(S + 1, i, D - (S + 1))) S++, D -= S, T++;
            else if (F(S, i, D - S)) D -= S, T++;
            else S--, D -= S, T++;
        }

        cout << T << "\n";
    }

    return 0;
}