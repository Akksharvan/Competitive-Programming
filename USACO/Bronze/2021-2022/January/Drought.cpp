#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> hunger_values(N);
		long long int minimum_bags = 0;
		bool answered = false;

		for (int i = 0; i < N; i++) {
			cin >> hunger_values[i];
		}

		if (N == 1) {
			cout << "0" << "\n";
			continue;
		}

		for (int c = 0; c < 2; c++) {
			for (int i = 1; i < N - 1; i++) {
				int difference = hunger_values[i] - hunger_values[i - 1];

				if (difference > 0) {
					minimum_bags += (2 * difference);
					hunger_values[i + 1] -= difference;
					hunger_values[i] = hunger_values[i - 1];
				}
			}
			
			if (hunger_values[N - 1] > hunger_values[N - 2]) {
				cout << "-1" << "\n";
				answered = true;
				break;
			}
			reverse(hunger_values.begin(), hunger_values.end());
		}

		if (!answered) {
			if (hunger_values[0] < 0) {
				cout << "-1" << "\n";
			}
			else {
				cout << minimum_bags << "\n";
			}
		}
	}

	return 0;
}