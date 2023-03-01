#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C; array<int, 7> D;
    for (int &d : D) cin >> d;

	sort(begin(D), end(D)); A = D[0], B = D[1]; C = D[6] - (D[0] + D[1]);
	cout << A << " " << B << " " << C << "\n";

	return 0;
}