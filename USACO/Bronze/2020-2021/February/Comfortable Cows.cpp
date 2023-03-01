#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> C, CC;

bool foo (int x, int y) {
	if (x < 0 || x > 1000 || y < 0 || y > 1000) return 0;

	int AC = 0;
	AC += C.count({x + 1, y});
	AC += C.count({x - 1, y});
	AC += C.count({x, y + 1});
	AC += C.count({x, y - 1});

	if (AC == 3) return 1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		C.insert({x, y});

		if (foo(x, y)) CC.insert({x, y});

		if (foo(x + 1, y) && C.count({x + 1, y})) CC.insert({x + 1, y});
		else if (CC.count({x + 1, y})) CC.erase({x + 1, y});
	
		if (foo(x - 1, y) && C.count({x - 1, y})) CC.insert({x - 1, y});
		else if (CC.count({x - 1, y})) CC.erase({x - 1, y});

		if (foo(x, y + 1) && C.count({x, y + 1})) CC.insert({x, y + 1});
		else if (CC.count({x, y + 1})) CC.erase({x, y + 1});

		if (foo(x, y - 1) && C.count({x, y - 1})) CC.insert({x, y - 1});
		else if (CC.count({x, y - 1})) CC.erase({x, y - 1});

		cout << (int) CC.size() << "\n";
	}

	return 0;
}