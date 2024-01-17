#include <bits/stdc++.h>
using namespace std;

bool F (vector<long long> &A) {
    int K = 0; for (long long &i : A) if (i < 0) K++;
    return (!(K & 1) ? 1 : 0);
}

void solve () {
    long long N, R = 0; string S; cin >> N >> S; unordered_set<char> A;
    for (long long i = 0; i < N; i++) if (!A.count(S[i])) A.insert(S[i]), R += (N - i);

    cout << R << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}