#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int N, K;
	cin >> N >> K;

	vector<int> diamonds(N);
	for (int i = 0; i < N; i++) {
		cin >> diamonds[i];
	}

	sort(diamonds.begin(), diamonds.end());

	int displayed_diamonds = 0;

	int left = 0;
	int right = 0;
	int current_diamonds = 0;
	
	map<int, int> left_diamonds, right_diamonds;

	while (left < N) {
		while (right < N) {
			if (diamonds[right] - diamonds[left] <= K) {
				current_diamonds++;
				right++;
			} else {
				break;
			}
		}
		
		displayed_diamonds = max(displayed_diamonds, current_diamonds);
		left_diamonds[left] = max(left_diamonds[left], current_diamonds);
		
		left++;
		current_diamonds--;
	}

	left = N - 1;
	right = N - 1;
	current_diamonds = 0;
	
	while (right >= 0) {
		while (left >= 0) {
			if (diamonds[right] - diamonds[left] <= K) {
				current_diamonds++;
				left--;				
			} else {
				break;
			}
		}

		displayed_diamonds = max(displayed_diamonds, current_diamonds);
		right_diamonds[right] = max(right_diamonds[right], current_diamonds);
		
		right--;
		current_diamonds--;
	}

	int max_down = 0;
	for (const pair<int, int> &left_diamond : left_diamonds) {
		displayed_diamonds = max(displayed_diamonds, left_diamond.second + max_down);
		max_down = max(max_down, right_diamonds[left_diamond.first]);
	}

	cout << displayed_diamonds << "\n";
	return 0;
}