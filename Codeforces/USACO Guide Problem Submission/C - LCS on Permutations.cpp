#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N), B(N);

    for (auto &i : A) cin >> i;
    for (auto &i : B) cin >> i;

    map<int, int> C; for (int i = 0; i < N; i++) C[A[i]] = i;
    for (int i = 0; i < N; i++) B[i] = C[B[i]];

    vector<int> DP;
    for (auto &i : B) {
        auto D = lower_bound(begin(DP), end(DP), i);
        if (D == end(DP)) DP.push_back(i); else *D = i;
    }

    cout << size(DP) << "\n";
    return 0;
}