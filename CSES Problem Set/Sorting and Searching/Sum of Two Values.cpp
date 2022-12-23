#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;

	vector<pair<int, int>> values;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		values.push_back({value, i + 1});
	}

	sort(values.begin(), values.end());

	int i = 0, j = n - 1;

	while (i < j) {
		long long int sum = (long long) values[i].first + (long long) values[j].first;
		if (sum == x) {
			cout << values[i].second << " " << values[j].second << "\n";
			return 0;
		}
		else if (sum < x) {
			i++;
		}
		else if (sum > x) {
			j--;
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}
