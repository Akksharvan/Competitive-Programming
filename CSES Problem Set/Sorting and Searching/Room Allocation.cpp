#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<pair<int, int>, int>> customers(n);

	for (int i = 0; i < n; i++) {
		cin >> customers[i].first.first >> customers[i].first.second;
		customers[i].second = i;
	}

	sort(customers.begin(), customers.end());

	int rooms_needed = 1;

	priority_queue<pair<int, int>> rooms;
	vector<int> room_logbook(n);

	rooms.push({0, rooms_needed});

	for (const pair<pair<int, int>, int> &customer : customers) {
		int arrival = customer.first.first;
		int departure = (customer.first.second) * (-1);
		int customer_number = customer.second;

		pair<int, int> top_customer = rooms.top();

		if (arrival > ((top_customer.first) * (-1))) {
			rooms.pop();
			rooms.push({departure, top_customer.second});
			room_logbook[customer_number] = top_customer.second;
		} else {
			rooms_needed++;
			rooms.push({departure, rooms_needed});
			room_logbook[customer_number] = rooms_needed;
		}
	}

	cout << rooms_needed << "\n";

	for (const int &room_number : room_logbook) {
		cout << room_number << " ";
	}

	return 0;
}