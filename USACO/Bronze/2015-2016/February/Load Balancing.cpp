#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	
	int N, B; cin >> N >> B;
	vector<int> X(N), Y(N);
	set<int> V, H;

	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		V.insert(X[i] + 1);
		H.insert(Y[i] + 1);
	}
	
	int res = N;
	for (const int v : V) {
		for (const int h : H) {
			int tl = 0, tr = 0;
			int bl = 0, br = 0;
			
			for (int i = 0; i < N; i++) {
                if (X[i] < v && Y[i] > h) tl++;
                else if (X[i] > v && Y[i] > h) tr++;
                else if (X[i] < v && Y[i] < h) bl++;
                else if (X[i] > v && Y[i] < h) br++;
			}
			
			res = min(res, max({tl, tr, bl, br}));
		}
	}

	cout << res << endl;
}