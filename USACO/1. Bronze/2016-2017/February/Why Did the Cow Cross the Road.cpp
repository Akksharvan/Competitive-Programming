#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crossroad.in", "r", stdin);
	freopen("crossroad.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	map<int, bool> cows;
	int ret = 0;

	for (int i = 0; i < N; i++) {
		int cow, side;
		cin >> cow >> side;

		if (!cows.count(cow)) cows[cow] = side;
		else if (side != cows[cow]) ret++, cows[cow] = side;
	}

	cout << ret << "\n";
	return 0;
}