#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int W, H, x1, y1, x2, y2, w, h, x3, y3, x4, y4;
		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

		int minimum_distance = INT32_MAX;
		bool possible = false;

		if (y2 + (h - y1) <= H) {
			possible = true;
			if (h - y1 <= 0) {
				minimum_distance = 0;
			}
			else {
				minimum_distance = min(minimum_distance, h - y1);
			}
		}

		if (y1 - (y2 - (H - h)) >= 0) {
			possible = true;
			if ((H - h) >= y2) {
				minimum_distance = 0;
			}
			else {
				minimum_distance = min(minimum_distance, y2 - (H - h));
			}
		}

		if (x2 + (w - x1) <= W) {
			possible = true;
			if (w - x1 <= 0) {
				minimum_distance = 0;
			}
			else {
				minimum_distance = min(minimum_distance, w - x1);
			}
		}

		if (x1 - (x2 - (W - w)) >= 0) {
			possible = true;
			if ((W - w) >= x2) {
				minimum_distance = 0;
			}
			else {
				minimum_distance = min(minimum_distance, x2 - (W - w));
			}
		}

		if (!possible) {
			minimum_distance = -1;
		}

		cout << minimum_distance << "\n";
	}

	return 0;
}