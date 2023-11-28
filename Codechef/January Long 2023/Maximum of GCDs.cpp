#include <bits/stdc++.h>
using namespace std;

void solve () {
    int N; cin >> N;
    vector<int> A(N); for (int &i : A) cin >> i;
    
    vector<map<int, int>> B(N); for (int i = 0; i < N; i++) B[i][A[i]] = 1;
    for (int i = 0; i < N - 1; i++) for (auto [j, k] : B[i]) { int C = gcd(A[i + 1], j); B[i + 1][C] = max(B[i + 1][C], k + 1); }
    
    vector<int> R(N + 1); for (int i = 0; i < N; i++) for (auto [j, k] : B[i]) R[k] = max(R[k], j);
    for (int i = 1; i <= N; i++) cout << R[i] << " ";
    
    cout << "\n"; return;
}

int main () {
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}