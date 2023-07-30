#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
 
	string N, M;
	cin >> N >> M;
 
	int DP[5001][5001];
	for (int i = 0; i <= 5000; i++) fill(begin(DP[i]), end(DP[i]), INT_MAX);
 
	for (int i = 0; i <= size(N); i++) {
		for (int j = 0; j <= size(M); j++) {
			if (i == 0 && j == 0) DP[i][j] = 0;
			else if (i == 0) DP[i][j] = j;
			else if (j == 0) DP[i][j] = i;
			else {
				DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);
				DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);
				DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + !(N[i - 1] == M[j - 1]));
			}
		}
	}
 
	cout << DP[size(N)][size(M)] << "\n";
	return 0;
}