#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> C(N);
	for (int &c : C) cin >> c;
	sort(C.rbegin(), C.rend());

	long long int optimal_tuition = C[0];
	long long int maximum_tuition = C[0];

	for (int i = 0; i < N; i++) {
		long long int tuition_rate = C[i];

		while (i + 1 < N && tuition_rate <= C[i + 1]) {
			i++;
		}

		long long int tuition = (i + 1) * tuition_rate;
		if (tuition > maximum_tuition) {
			optimal_tuition = tuition_rate;
			maximum_tuition = tuition;
		}
		else if (tuition == maximum_tuition) {
			optimal_tuition = min(tuition_rate, optimal_tuition);
		}
	}

	cout << maximum_tuition << spc << optimal_tuition << nl;
	return 0;
}