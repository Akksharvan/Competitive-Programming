#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	int X = ((N % 8) ? (N / 8) : (N / 8 - 1)), R = N % 8;

	if (R == 0) cout << (X * 15) + 14 << "\n";
	else if (R == 1) cout << (X * 15) + 1 << "\n";
	else if (R == 2) cout << (X * 15) + 2 << "\n";
	else if (R == 3) cout << (X * 15) + 4 << "\n";
	else if (R == 4) cout << (X * 15) + 7 << "\n";
	else if (R == 5) cout << (X * 15) + 8 << "\n";
	else if (R == 6) cout << (X * 15) + 11 << "\n";
	else if (R == 7) cout << (X * 15) + 13 << "\n";
	
	return 0;
}