#include <bits/stdc++.h>
using namespace std;

array<array<char, 500>, 500> G;
array<array<bool, 500>, 500> V;
set<char> S; int H, W; bool B = 0;

void foo (int x, int y, int u, int v) {
	if (x < 0 || x >= H) return;
	if (y < 0 || y >= W) return;

	if (S.find(G[x][y]) == end(S)) return;
	if (G[x][y] == 's' && G[u][v] != 'e') return;
	if (G[x][y] == 'n' && G[u][v] != 's') return;
	if (G[x][y] == 'u' && G[u][v] != 'n') return;
	if (G[x][y] == 'k' && G[u][v] != 'u') return;
	if (G[x][y] == 'e' && G[u][v] != 'k') return;
  
	if (V[x][y]) { return; } V[x][y] = 1;
	if (x == (H - 1) && y == (W - 1)) { B = 1; return; }
  
	foo(x - 1, y, x, y); foo(x + 1, y, x, y);
	foo(x, y - 1, x, y); foo(x, y + 1, x, y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	S.insert('s'); S.insert('n');
	S.insert('u'); S.insert('k');
	S.insert('e'); cin >> H >> W;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> G[i][j];
		}
	}
	
	int x = 0, y = 0; V[0][0] = 1;
	if (G[x][y] != 's') { cout << "No" << "\n"; return 0; }

	foo(x - 1, y, x, y); foo(x + 1, y, x, y);
	foo(x, y - 1, x, y); foo(x, y + 1, x, y);

	if (B) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}