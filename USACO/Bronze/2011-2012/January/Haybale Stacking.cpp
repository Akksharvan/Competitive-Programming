#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("stacking.in", "r", stdin);
	freopen("stacking.out", "w", stdout);

	int N, K;
	cin >> N >> K;

	vector<int> difference_haybales(N + 1);
	for(int i = 0; i < K; i++) {
		int start_index, end_index;
		cin >> start_index >> end_index;

		start_index--;

		difference_haybales[start_index]++;
		difference_haybales[end_index]--;
	}

	vector<int> hay_stacks(N);
	int accumulated_total = 0;

	for(int i = 0; i < N; i++) {
		accumulated_total += difference_haybales[i];
		hay_stacks[i] = accumulated_total;
	}

	sort(hay_stacks.begin(), hay_stacks.end());
	cout << hay_stacks[N/2] << "\n";

	return 0;
}