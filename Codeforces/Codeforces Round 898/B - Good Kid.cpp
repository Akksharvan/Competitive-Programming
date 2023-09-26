#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    *min_element(begin(A), end(A)) += 1;
    long long R = 1; for (long long &i : A) R *= i;

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