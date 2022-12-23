#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<array<int, 25>, 25> maze{};
array<array<array<bool, 19683>, 25>, 25> visited{};

array<bool, 19683> winning_states_reached{};
map<pair<int, int>, pair<int, int>> o_moves, m_moves;

long long int winning_states = 0;

int board_state (array<array<int, 3>, 3>& b) {
	int state = 0;
	int power = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			state += b[i][j] * pow(3, power);
			power++;
		}
	}

	return state;
}

bool winning_state (array<array<int, 3>, 3>& b) {
	int s = 0;

	for (int i = 0; i < 3; i++) {
		s = (100 * b[i][0]) + (10 * b[i][1]) + b[i][2];

		if (s == 112 || s == 211) {
			return true;
		}
	}

	for (int j = 0; j < 3; j++) {
		s = (100 * b[0][j]) + (10 * b[1][j]) + b[2][j];

		if (s == 112 || s == 211) {
			return true;
		}
	}
	
	s = (100 * b[0][0]) + (10 * b[1][1]) + b[2][2];

	if (s == 112 || s == 211) {
		return true;
	}

	s = (100 * b[0][2]) + (10 * b[1][1]) + b[2][0];

	if (s == 112 || s == 211) {
		return true;
	}
	
	return false;
}

void floodfill (int x, int y, array<array<int, 3>, 3> b) {
	int s = board_state(b);

	if (maze[x][y] == 3|| visited[x][y][s]) {
		return;
	}

	visited[x][y][s] = true;

	if (maze[x][y] == 1) {
		int V = 1;
		int X = o_moves[{x, y}].first;
		int Y = o_moves[{x, y}].second;

		if (!b[X][Y]) {
			b[X][Y] = V;
		}
	}
	else if (maze[x][y] == 2) {
		int V = 2;
		int X = m_moves[{x, y}].first;
		int Y = m_moves[{x, y}].second;

		if (!b[X][Y]) {
			b[X][Y] = V;
		}
	}
	
	if (winning_state(b)) {
		if (!winning_states_reached[board_state(b)]) {
			winning_states_reached[board_state(b)] = true;
			winning_states++;
		}

		return;
	}

	floodfill(x + 1, y, b);
	floodfill(x - 1, y, b);
	floodfill(x, y + 1, b);
	floodfill(x, y - 1, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X, Y;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < (3 * N); j += 3) {
			int x = i;
			int y = j/3;

			if (s[j] == '#') {
				maze[x][y] = 3;
			}
			else if (s[j] == 'B') {
				maze[x][y] = 0;
				X = x, Y = y;
			}
			else if (s[j] == '.') {
				maze[x][y] = 0;
			}
			else if (s[j] == 'O') {
				maze[x][y] = 1;
				o_moves[{x, y}] = {int(s[j + 1] - '0') - 1, int(s[j + 2] - '0') - 1};
			}
			else if (s[j] == 'M') {
				maze[x][y] = 2;
				m_moves[{x, y}] = {int(s[j + 1] - '0') - 1, int(s[j + 2] - '0') - 1};
			}
		}
	}

	array<array<int, 3>, 3> b{};
	floodfill(X, Y, b);

	cout << winning_states << nl;
	return 0;
}