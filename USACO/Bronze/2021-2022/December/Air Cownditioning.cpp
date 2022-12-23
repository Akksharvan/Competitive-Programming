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

	vector<int> ideal_temperatures(N), initial_temperatures(N), gradient_temperatures(N);
	for (int i = 0; i < N; i++) {
		cin >> ideal_temperatures[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> initial_temperatures[i];
	}

	for (int i = 0; i < N; i++) {
		gradient_temperatures[i] = ideal_temperatures[i] - initial_temperatures[i];
	}

	int commands = 0;
	for (int i = 0; i < N; i++) {
		if (i < N - 1) {
			if (gradient_temperatures[i] < 0) {
				if (gradient_temperatures[i + 1] < 0) {
					if (gradient_temperatures[i] < gradient_temperatures[i + 1]) {
						commands += abs(gradient_temperatures[i + 1] - gradient_temperatures[i]);
					}
				}
				else {
					commands += abs(0 - gradient_temperatures[i]);
				}
			}
			else if (gradient_temperatures[i] > 0) {
				if (gradient_temperatures[i + 1] > 0) {
					if (gradient_temperatures[i] > gradient_temperatures[i + 1]) {
						commands += abs(gradient_temperatures[i] - gradient_temperatures[i + 1]);
					}
				}
				else {
					commands += abs(gradient_temperatures[i]);
				}
			}
		}
		else {
			commands += abs(0 - gradient_temperatures[i]);
		}
	}

	cout << commands << nl;
	return 0;
}