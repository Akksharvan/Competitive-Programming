#include <iostream>
#include <vector>

using namespace std;

const int MOD = 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int N;
	cin >> N;

	vector<long long int> ID_List(N);
	for (long long int& ID : ID_List) {
		cin >> ID;
	}

	vector<long long int> prefix(N + 1);
	for (int i = 0; i < N; i++) {
		prefix[i + 1] = prefix[i] + ID_List[i];
	}

	for (int i = 1; i < N + 1; i++) {
		prefix[i] = prefix[i] % MOD;
	}

	int longest_consecutive_counter = 0;
	vector<int> first_index(MOD, N);

	for (int i = 1; i < N + 1; i++) {
		int remainder = prefix[i];
		first_index[remainder] = min(first_index[remainder], i);
		longest_consecutive_counter = max(longest_consecutive_counter, i - first_index[remainder]);
	}

	cout << longest_consecutive_counter << "\n";

	return 0;
}