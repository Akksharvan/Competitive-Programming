#include <bits/stdc++.h>
using namespace std;
 
int C[3][101];
int R[3][101];
 
bool foo (int x, int y) { return R[x][y] == max(max(R[0][y], R[1][y]), R[2][y]); }
 
int main(void) {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int N; cin >> N;
	int c, d, x; string S;
	
	for (int i=0; i<N; i++) {
		cin >> d >> S >> x;
		if (S == "Bessie") c = 0;
		if (S == "Elsie") c = 1;
		if (S == "Mildred") c = 2;
		C[c][d] = x;
	}

	int res = 0; for (int c = 0; c < 3; c++) R[c][0] = 7;
	for (int c = 0; c < 3; c++) for (int d = 1; d <= 100; d++) R[c][d] = R[c][d-1] + C[c][d];
	for (int d = 1; d <= 100; d++) if (foo (0, d - 1) != foo (0, d) || foo (1, d - 1) != foo (1, d) || foo (2, d - 1) != foo (2, d)) res++;

	cout << res << "\n";
	return 0;
}