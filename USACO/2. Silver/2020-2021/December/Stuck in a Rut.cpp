#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

bool north_cmp (const array<int, 3>& a, const array<int, 3>& b) {
	return a[0] < b[0];
}

bool east_cmp (const array<int, 3>& a, const array<int, 3>& b) {
	return a[1] < b[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<array<int, 3>> north_cows, east_cows;
	vector<int> cows_stopped(N);
	vector<bool> stopped_cows(N);

	for (int i = 0; i < N; i++) {
		char d;
		int x, y;
		cin >> d >> x >> y;

		if (d == 'N') {
			north_cows.push_back({x, y, i});
		}
		else if (d == 'E') {
			east_cows.push_back({x, y, i});
		}
	}

	sort(north_cows.begin(), north_cows.end(), north_cmp);
	sort(east_cows.begin(), east_cows.end(), east_cmp);

	for (const array<int, 3> north_cow : north_cows) {
		for (const array<int, 3> east_cow : east_cows) {
			int ncx = north_cow[0], ncy = north_cow[1], nci = north_cow[2];
			int ecx = east_cow[0], ecy = east_cow[1], eci = east_cow[2];

			if (!stopped_cows[nci] && !stopped_cows[eci]) {
				if (ncx > ecx && ncy < ecy)	{
					if (ncx - ecx < ecy - ncy) {
						stopped_cows[nci] = true;
						cows_stopped[eci] += cows_stopped[nci] + 1;
					}
					else if (ecy - ncy < ncx - ecx) {
						stopped_cows[eci] = true;
						cows_stopped[nci] += cows_stopped[eci] + 1;
					}
				}			
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << cows_stopped[i] << nl;
	}

	return 0;
}