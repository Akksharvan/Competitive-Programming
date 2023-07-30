#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<long long> A(N); for (long long &i : A) cin >> i;

    long long R = 0;
    for (long long &i : A) R += abs(i);

    int S = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= 0) continue;
        S++; while (i < N && A[i] <= 0) i++;
    }

    cout << R << " " << S << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T; cin >> T;
    while (T--) solve();
	
	return 0;
}