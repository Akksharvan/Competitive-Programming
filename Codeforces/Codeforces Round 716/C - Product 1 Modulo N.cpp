#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N; cin >> N;
    vector<long long> A; for (int i = 1; i < N; i++) if (gcd(i, N) == 1) A.push_back(i);
    
    long long B = 1, R = N; for (long long &i : A) B *= i, B %= N; 
    if (B != 1) R = B;

    cout << size(A) - (R != N) << "\n";
    for (long long &i : A) if (i != R) cout << i << " ";
    
    return 0;
}