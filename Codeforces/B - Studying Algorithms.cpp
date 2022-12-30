#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	int N, X;
	cin >> N >> X;
	
	priority_queue<int> learning_times;
	for (int i = 0; i < N; i++) {
		int learning_time;
		cin >> learning_time;
		learning_times.push(learning_time * -1);
	}

	int time_spent_learning = 0;
	int algorithms_learned = 0;
	while (!learning_times.empty()) {
		if (time_spent_learning + (-1 * learning_times.top()) <= X) {
			time_spent_learning += (-1 * learning_times.top());
			algorithms_learned++;
			learning_times.pop();
		}
		else {
			break;
		}
	}

	cout << algorithms_learned << nl;
	return 0;
}