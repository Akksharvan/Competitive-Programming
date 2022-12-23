#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main() {
	int t;
	cin >> t;
	
	map<string, int> s_numbers;

	while (t--) {
		char operation;
		long long int a;
		cin >> operation >> a;

		string current_number;

		while (a > 0) {
			current_number += to_string((a % 10) % 2);
			a /= 10;
		}

		while (current_number.length() < 18) {
			current_number += "0";
		}

		if (operation == '+') {
			s_numbers[current_number]++;
		}
		else if (operation == '-') {
			s_numbers[current_number]--;
		}
		else {
			cout << s_numbers[current_number] << nl;
		}
	}

	return 0;
}