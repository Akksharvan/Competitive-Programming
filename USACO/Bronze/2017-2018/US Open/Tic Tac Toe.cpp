#include <bits/stdc++.h>
using namespace std;

const int WIDTH = 3;

vector<string> B(WIDTH);
set<set<char>> W[WIDTH + 1];

void insert(vector<pair<int, int>> coordinates) {
	set<char> C; for (const pair<int, int> &p : coordinates) C.insert(B[p.first][p.second]);
	W[C.size()].insert(C); return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	for (int r = 0; r < WIDTH; r++) cin >> B[r];
	for (int i = 0; i < WIDTH; i++) insert({{i, 0}, {i, 1}, {i, 2}});
	
	for (int i = 0; i < WIDTH; i++) insert({{0, i}, {1, i}, {2, i}});
	insert({{0, 0}, {1, 1}, {2, 2}}); insert({{2, 0}, {1, 1}, {0, 2}});

	cout << W[1].size() << "\n";
	cout << W[2].size() << "\n";

	return 0;
}