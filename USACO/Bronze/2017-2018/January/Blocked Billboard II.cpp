#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	vector<int> A(5), B(5); for (int i = 1; i <= 4; i++) { cin >> A[i] >> B[i]; }

	if (A[4] >= A[2] && A[3] <= A[1] && B[4] >= B[2] && B[3] <= B[1]) cout << 0;
	else if (A[3] <= A[1] && B[3] <= B[1] && B[4] > B[1] && A[4] >= A[2]) cout << (A[2] - A[1]) * (B[2] - B[4]);
	else if (B[3] < B[2] && A[3] <= A[1] && B[4] >= B[2] && A[4] >= A[2]) cout << (A[2] - A[1]) * (B[3] - B[1]);
	else if (A[4] > A[1] && A[3] <= A[1] && B[4] >= B[2] && B[3] <= B[1]) cout << (A[2] - A[4]) * (B[2] - B[1]);
	else if (A[3] < A[2] && A[4] >= A[2] && B[4] >= B[2] && B[3] <= A[1]) cout << (A[3] - A[1]) * (B[2] - B[1]);
	else cout << (A[2] - A[1]) * (B[2] - B[1]); return 0;
}