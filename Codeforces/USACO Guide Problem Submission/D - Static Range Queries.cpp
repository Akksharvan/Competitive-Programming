#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q; cin >> N >> Q;

    vector<array<int, 3>> A(N);
    vector<array<int, 2>> B(Q);

    for (auto &i : A) cin >> i[0] >> i[1] >> i[2];
    for (auto &i : B) cin >> i[0] >> i[1];

    set<int> C;
    C.insert(-1);

    for (auto &i : A) C.insert(i[0]), C.insert(i[1]);
    for (auto &i : B) C.insert(i[0]), C.insert(i[1]), C.insert(i[1] - 1);

    map<int, int> D;
    map<int, int> E;

    long long I = 0;
    for (auto &i : C) D[i] = I, E[I] = i, I++;

    for (auto &i : A) i[0] = D[i[0]], i[1] = D[i[1]];
    for (auto &i : B) i[0] = D[i[0]], i[1] = D[i[1]];

    vector<long long> DP(I + 1);
    for (auto &i : A) DP[i[0]] += i[2], DP[i[1]] -= i[2];

    for (int i = 1; i <= I; i++) DP[i] += DP[i - 1];
    for (int i = 0; i < I; i++) DP[i] = (E[i + 1] - E[i]) * DP[i];
    
    for (int i = 1; i <= I; i++) DP[i] += DP[i - 1];
    for (auto &i : B) cout << DP[i[1] - 1] - DP[i[0] - 1] << "\n";

    return 0;
}