#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A, B; cin >> A >> B;
	cout << (!(A % B) ? A / B : (A / B) + 1) << "\n";

	return 0;
}