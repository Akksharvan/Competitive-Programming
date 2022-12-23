#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

struct Rectangle {
	int x1, x2, y1, y2;
	Rectangle(int a, int b, int c, int d) {
		x1 = a, x2 = b;
		y1 = c, y2 = d;
	}
};

array<array<char, 20>, 20> image;
array<array<bool, 20>, 20> visited;

vector<Rectangle> PCLs;

void floodfill (pair<int, int> point, Rectangle r, char color) {
	if (point.first < r.x1 || point.first > r.x2) {
		return;
	}
	else if (point.second < r.y1 || point.second > r.y2) {
		return;
	}
	else if (image[point.first][point.second] != color) {
		return;
	}
	else if (visited[point.first][point.second]) {
		return;
	}

	visited[point.first][point.second] = true;
	floodfill({point.first - 1, point.second}, r, color);
	floodfill({point.first + 1, point.second}, r, color);
	floodfill({point.first, point.second - 1}, r, color);
	floodfill({point.first, point.second + 1}, r, color);
}

void new_PCL (Rectangle r) {
	map<char, int> cbc;

	for (int i = r.x1; i <= r.x2; i++) {
		for (int j = r.y1; j <= r.y2; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = r.x1; i <= r.x2; i++) {
		for (int j = r.y1; j <= r.y2; j++) {
			if (!visited[i][j]) {
				cbc[image[i][j]]++;
				floodfill({i, j}, r, image[i][j]);
			}
		}
	}

	if (sz(cbc) != 2) {
		return;
	}
	else if (begin(cbc) -> second == 1 && next(begin(cbc)) -> second == 1) {
		return;
	}
	else if (begin(cbc) -> second != 1 && next(begin(cbc)) -> second != 1) {
		return;
	}
	else {
		PCLs.push_back(r);
	}
}

bool check_PCL (int i) {
	for (int j = 0; j < sz(PCLs); j++) {
		if (i != j) {
			if (PCLs[i].x1 >= PCLs[j].x1 && PCLs[i].x2 <= PCLs[j].x2) {
				if (PCLs[i].y1 >= PCLs[j].y1 && PCLs[i].y2 <= PCLs[j].y2) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			image[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = i; k < N; k++) {
				for (int l = j; l < N; l++) {
					Rectangle r (i, k, j, l);
					new_PCL(r);
				}
			}
 		}
	}

	int PCL_counter = 0;

	for (int i = 0; i < sz(PCLs); i++) {
		PCL_counter += check_PCL(i);
	}

	cout << PCL_counter << nl;
	return 0;
}