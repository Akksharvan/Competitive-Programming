#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	array<int, 7> integers;

	for (int i = 0; i < 7; i++) {
		cin >> integers[i];
	}
	sort(begin(integers), end(integers));

	A = integers[0];
	B = integers[1];
	C = integers[6] - (integers[0] + integers[1]);


	cout << A << spc << B << spc << C << nl;
	return 0;
}