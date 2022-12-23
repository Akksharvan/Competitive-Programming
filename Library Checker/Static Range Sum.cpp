#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;

	vector<long long int> integer_list(N);
	for (long long int& integer : integer_list) {
		cin >> integer;
	}

	vector<long long int> prefix(N + 1);

	for (int i = 0; i < N; i++) {
		prefix[i + 1] = integer_list[i] + prefix[i];
	}

	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;

		cout << prefix[r] - prefix[l] << "\n";
	}

	return 0;
}