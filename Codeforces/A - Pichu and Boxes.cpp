#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	a *= 12, b *= 12, c *= 12;
	cout << (a / 8) * (b / 8) * (c / 8) << "\n";
	
	return 0;
}