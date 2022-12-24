#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("gates.in", "r", stdin);
	freopen("gates.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	string S; cin >> S;

	set<pair<pair<int, int>, pair<int, int>>> VE;
	set<pair<int, int>> VN;

	pair<int, int> op = {0, 0};
	VN.insert(op);

	int r = 1;
	for (int i = 0; i < N; i++) {
		pair<int, int> np = op;

		if (S[i] == 'N') np.second++;
		else if (S[i] == 'S') np.second--;
		else if (S[i] == 'E') np.first++;
		else np.first--;

		if (VE.find({op, np}) == VE.end() && VN.find(np) != VN.end()) r++;
		
		VE.insert({op, np});
		VE.insert({np, op});
		
		VN.insert(np);
		op = np;
	}

	cout << (r - 1) << "\n";
	return 0;
}