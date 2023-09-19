#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

array<int, (int) 1e5> ocp, ccp, cbcc;
array<set<int>, (int) 1e5> csu, ccs;
array<bool, (int) 1e5> v;

int cc = -1;

void dfs (int node, int component) {
	v[node] = true;
	cbcc[node] = component;

	for (const int& i : csu[node]) {
		ccs[component].insert(i);
	}

	if (!v[ccp[ocp[node]]]) {
		dfs(ccp[ocp[node]], component);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		ccp[i] = i;
		ocp[i] = i;
		csu[i].insert(i);
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;

		a--;
		b--;

		int c = ccp[a], d = ccp[b];
		ccp[a] = d, ccp[b] = c;

		csu[ccp[a]].insert(a);
		csu[ccp[b]].insert(b);
	}



	for (int i = 0; i < N; i++) {
		if (!v[i]) {
			dfs(i, ++cc);
		}
 	}

	for (int i = 0; i < N; i++) {
		cout << sz(ccs[cbcc[i]]) << nl;
	}

	return 0;
}