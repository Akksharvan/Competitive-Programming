#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, S = 3; cin >> N;
    array<char, 3> A = {'a', 'a', 'a'};

    for (int i = 1; i < 26; i++) {
        if (S == N) break;
        A[2] += 1; S++;
    }

    for (int i = 1; i < 26; i++) {
        if (S == N) break;
        A[1] += 1; S++;
    }

    for (int i = 1; i < 26; i++) {
        if (S == N) break;
        A[0] += 1; S++;
    }

    for (int i = 0; i < 3; i++) cout << A[i];
    cout << "\n"; return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}