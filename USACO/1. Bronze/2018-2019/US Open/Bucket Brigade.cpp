#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);

	int A, B, C, D, E, F;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c; cin >> c;
			if (c == 'B') A = i, B = j;
			if (c == 'R') C = i, D = j;
			if (c == 'L') E = i, F = j;
		}
	}

	if (A == E && A == C && C == E && ((B < D && D < F) || (B > D && D > F))) cout << (abs(A - E) + abs(B - F) + 1) << "\n";
	else if (B == F && B == D && D == F && ((A < C && C < E) || (A > C && C > E))) cout << (abs(A - E) + abs(B - F) + 1) << "\n";
	else cout << (abs(A - E) + abs(B - F) - 1) << "\n";

	return 0;
}