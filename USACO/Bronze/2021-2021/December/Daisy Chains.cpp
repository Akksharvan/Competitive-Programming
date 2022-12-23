#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> flowers(N + 1), petals(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> flowers[i];
		petals[i] = petals[i - 1] + flowers[i];
	}

	int average_flowers = N;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int total_petals = petals[j] - petals[i - 1];
			int total_flowers = j - i + 1;

			if (total_petals % total_flowers == 0) {
				int average_petals = total_petals / total_flowers;

				for (int k = i; k <= j; k++) {
					if (flowers[k] == average_petals) {
						average_flowers++;
						break;
					}
				}
			}
		}
	}

	cout << average_flowers << nl;
	return 0;
}