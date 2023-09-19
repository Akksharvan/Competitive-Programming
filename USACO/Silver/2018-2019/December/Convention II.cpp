#include <bits/stdc++.h>

using namespace std;

#define nl "\n"

struct Cow {
	int arrival_time, usage_time, priority;
};

struct Bovine_Compare {
	bool operator() (const Cow& cow_one, const Cow& cow_two) {
		return cow_one.priority > cow_two.priority;
	}
};

bool bovine_comparison(const Cow& cow_one, const Cow& cow_two) {
	if (cow_one.arrival_time == cow_two.arrival_time) {
		return cow_one.priority > cow_two.priority;
	}
	else {
		return cow_one.arrival_time < cow_two.arrival_time;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

	int N;
	cin >> N;

	vector<Cow> cows(N);
	for (int i = 0; i < N; i++) {
		cows[i].priority = i + 1;
		cin >> cows[i].arrival_time >> cows[i].usage_time;
	}

	sort(cows.begin(), cows.end(), bovine_comparison);

	int max_wait = 0;
	for (vector<Cow>::iterator it = cows.begin(); next(it) != cows.end(); it++) {
		Cow current_cow = *it;
		int current_time = current_cow.arrival_time + current_cow.usage_time;

		priority_queue<Cow, vector<Cow>, Bovine_Compare> cow_line;
		while (next(it) != prev(cows.end()) && next(it) -> arrival_time <= current_time) {
			cow_line.push(*++it);
		}

		while (!cow_line.empty()) {
			current_cow = cow_line.top();
			cow_line.pop();

			max_wait = max(max_wait, current_time - current_cow.arrival_time);
			current_time += current_cow.usage_time;

			while (next(it) != prev(cows.end()) && next(it) -> arrival_time <= current_time) {
				cow_line.push(*++it);
				cerr << it -> arrival_time << nl;
			}
		}
	}

	cout << max_wait << nl;
	return 0;
}
