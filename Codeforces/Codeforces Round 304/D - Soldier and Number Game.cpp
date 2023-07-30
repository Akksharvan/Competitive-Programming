#include <bits/stdc++.h>
using namespace std;

array<int, (int) 5e6 + 1> S; array<int, (int) 5e6 + 1> C, DP;
void foo() { for (int i = 2; i <= (int) 5e6; i++) { if (!S[i]) { for (int j = i; j <= (int) 5e6; j += i) { S[j] = i; } } } }
void bar() { for (int i = 2; i <= (int) 5e6; i++) { if (i == S[i]) { C[i] = 1; } else { C[i] = C[i / S[i]] + 1; } } for (int i = 1; i <= (int) 5e6; i++) { DP[i] = C[i] + DP[i - 1]; } }

void solve() {
	int a, b; cin >> a >> b;
	cout << DP[a] - DP[b] << "\n"; return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T; foo(); bar();
	for (int t = 1; t <= T; t++) solve();
	
	return 0;
}