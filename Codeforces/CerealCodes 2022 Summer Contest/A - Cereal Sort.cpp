#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N; cin >> N;
    map<long long, long long> A;

    for (long long i = 0; i < N; i++) {
        long long x; cin >> x;
        A[x]++;
    }

    long long B = 0, C = 0;
    for (const pair<long long, long long> &i : A) {
        B += (N - C);
        C += i.second;
    }

    cout << B << "\n";
    return 0;
}