#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main() {
	long long int l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;

	long long int time;
	if (min(r1, r2) < max(l1, l2)) {
		cout << 0 << nl;
		return 0;
	}
	else {
		time = min(r1, r2) - max(l1, l2) + 1 - (k <= min(r1, r2) && k >= max(l1, l2));
		cout << time << nl;
		return 0;
	}
}