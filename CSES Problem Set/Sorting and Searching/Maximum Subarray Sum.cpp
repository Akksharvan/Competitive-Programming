#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long int> prefix(n + 1);
	for (int i = 0; i < n; i++) {
		long long int integer;
		cin >> integer;

		prefix[i + 1] = prefix[i] + integer; 
	}

	long long int maximum_subarry_sum = prefix[1];
	long long int minimum_subarray_sum = prefix[0];

	for (int i = 1; i <= n; i++) {
		maximum_subarry_sum = max(maximum_subarry_sum, prefix[i] - minimum_subarray_sum);
		minimum_subarray_sum = min(minimum_subarray_sum, prefix[i]);
	}

	cout << maximum_subarry_sum << "\n";

	return 0;
}