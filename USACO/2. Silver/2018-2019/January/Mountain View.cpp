#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MountainPeak {
	int x, y;
};

bool CMP(const MountainPeak& i, const MountainPeak& j) {
	if (i.x - i.y == j.x - j.y) {
		return (i.x + i.y > j.x + j.y);
	}
	else {
		return (i.x - i.y < j.x - j.y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);

	int N;
	cin >> N;

	vector<MountainPeak> mountains(N);
	for (int i = 0; i < N; i++) {
		cin >> mountains[i].x >> mountains[i].y;
	}

	sort(mountains.begin(), mountains.end(), CMP);
	int mountains_seen = 0;
	int max_position = -1;

	for (int i = 0; i < N; i++) {
		if (mountains[i].x + mountains[i].y > max_position) {
			mountains_seen++;
			max_position = mountains[i].x + mountains[i].y;
		}
	}

	cout << mountains_seen << "\n";
}
