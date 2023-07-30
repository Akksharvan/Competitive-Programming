#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
 
	int A, B;
	cin >> A >> B;
 
	int DP[501][501];
	for (int i = 0; i <= 500; i++) fill(begin(DP[i]), end(DP[i]), INT_MAX);
 
	for (int i = 0; i <= A; i++) {
		for (int j = 0; j <= B; j++) {
			if (i == j) DP[i][j] = 0;
			else {
				for (int k = 1; k < i; k++) DP[i][j] = min(DP[i][j], DP[k][j] + DP[i - k][j] + 1);
				for (int k = 1; k < j; k++) DP[i][j] = min(DP[i][j], DP[i][k] + DP[i][j - k] + 1);
			}
		}
	}
 
	cout << DP[A][B] << "\n";
	return 0;
}