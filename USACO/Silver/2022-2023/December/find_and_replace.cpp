#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a, b;
	cin >> a >> b;

	vector<int> A;
	vector<int> B;

	for (char &c : a) A.push_back(((c <= 90) ? (c - 64) : (c - 70)));
	for (char &c : b) B.push_back(((c <= 90) ? (c - 64) : (c - 70)));

	map<int, int> succ; int c = 0;
	for (int i = 0; i < (int) A.size(); i++) {
		if (!succ.count(A[i])) { succ[A[i]] = B[i]; c++; }
		else if (succ[A[i]] != B[i]) { cout << -1 << "\n"; return; }
	}

	vector<int> rem;
	for (const pair<int, int> &kp : succ) if (kp.first == kp.second) rem.push_back(kp.first);
	for (int &r : rem) succ.erase(r);

	map<int, vector<int>> pred;
	for (const pair<int, int> &kp : succ) {
		if (succ.count(kp.second)) pred[kp.second].push_back(kp.first);
	}

	int ret = (int) succ.size();
	map<int, bool> v;

	for (const pair<int, int> &kp : succ) {
		if (!v[kp.first]) {
			v[kp.first] = 1; bool c = 0;
			set<int> nds = { kp.first }; int k = kp.first;

			while (succ.count(succ[k])) {
				k = succ[k]; nds.insert(k);
				if (v[k]) { c = 1; cerr << k << "\n"; break; }
				v[k] = 1;
			}

			queue<int> pds;
			for (const int &nd : nds) for (const int &pd : pred[nd]) pds.push(pd);

			while (!pds.empty()) {
				int pd = pds.front(); pds.pop();
				if (!v[pd]) {
					v[pd] = 1; nds.insert(pd);
					for (int &p : pred[pd]) pds.push(p);
				}
			}

			for (const int &nd : nds) if ((int) pred[nd].size() > 1) c = 0;
			ret += c;
		}
	}

	if (ret > (int) succ.size() && c == 52) cout << -1 << "\n";
	else cout << ret << "\n";

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) solve();

	return 0;
}