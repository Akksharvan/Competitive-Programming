#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

struct Task {
	int duration, deadline;

	bool operator<(const Task& t) const {
		if (duration == t.duration) {
			return deadline < t.deadline;
		}
		else {
			return duration < t.duration;
		}
	}
};

int main() {
	int n;
	cin >> n;

	vector<Task> tasks(n);
	for (Task& t : tasks) {
		cin >> t.duration >> t.deadline;
	}

	sort(begin(tasks), end(tasks));

	long long int points = 0, current_time = 0;
	for (const Task& t : tasks) {
		current_time += t.duration;
		points += t.deadline - current_time;
	}

	cout << points << nl;
	return 0;
}