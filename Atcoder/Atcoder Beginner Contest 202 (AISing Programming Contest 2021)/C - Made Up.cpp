#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    vector<int> A(N); for (auto &i : A) cin >> i;
    vector<int> B(N); for (auto &i : B) cin >> i;
    vector<int> C(N); for (auto &i : C) cin >> i;

    map<int, long long> D; for (auto &i : A) D[i]++;
    map<int, long long> E; for (auto &i : C) E[B[i - 1]]++;

    long long R = 0;
    for (auto &[i, j] : D) R += (j * E[i]);

    cout << R << "\n";
    return 0;
}