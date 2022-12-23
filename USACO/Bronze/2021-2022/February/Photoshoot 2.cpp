#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> a_n(N);
	vector<int> b_n(N);

	map<int, int> a_index;

	for (int i = 0; i < N; i++) {
		cin >> a_n.at(i);
		a_index[a_n.at(i)] = i;
	}

	for (int i = 0; i < N; i++) {
		cin >> b_n.at(i);
	}

	int modifications = 0;

	vector<int> new_a_n(N);
	vector<int> new_b_n(N);

	for (int i = 0; i < N; i++) {
		new_a_n.at(a_index[b_n.at(i)]) = i;
		new_b_n.at(i) = i;
	}

	int max_value = new_a_n.at(0);

	for (int i = 0; i < N; i++) {
		if (new_a_n.at(i) < max_value) {
			modifications++;
		}
		else {
			max_value = max(max_value, new_a_n.at(i));
		}
	}

	cout << modifications << "\n";

    return 0;
}