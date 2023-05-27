/*
ID: akkshar1
TASK: milk
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	ios::sync_with_stdio(false);
	fin.tie(nullptr);
	
	int N, M; fin >> N >> M;
	vector<pair<int, int>> F(M); for (pair<int, int> &f : F) fin >> f.first >> f.second;
	
	sort(begin(F), end(F));

	int res = 0;
	for (pair<int, int> &f : F) {
		res += f.first * min(f.second, N);
		N -= min(f.second, N); if (!N) break;
	}

	fout << res << "\n";
	return 0;
}