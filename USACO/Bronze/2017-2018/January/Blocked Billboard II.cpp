#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	vector<int> A(4), B(4); for (int i = 0; i < 3; i++) { cin >> A[i] >> B[i]; }
	
	if (A[3] >= A[1] && A[2] <= A[0] && B[3] >= B[1] && B[2] <= B[0]) cout << 0;
	else if (A[2] <= A[0] && B[2] <= B[0] && B[3] > B[0] && A[3] >= A[1]) cout << (A[1] - A[0]) * (B[1] - B[3]);
	else if (B[2] < B[1] && A[2] <= A[0] && B[3] >= B[1] && A[3] >= A[1]) cout << (A[1] - A[0]) * (B[2] - B[0]);
	else if (A[3] > A[0] && A[2] <= A[0] && B[3] >= B[1] && B[2] <= B[0]) cout << (A[1] - A[3]) * (B[1] - B[0]);
	else if (A[2] < A[1] && A[3] >= A[1] && B[3] >= B[1] && B[2] <= A[0]) cout << (A[2] - A[0]) * (B[1] - B[0]);
	else cout << (A[1] - A[0]) * (B[1] - B[0]); return 0;
}