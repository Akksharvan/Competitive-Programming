#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> p(n);
		for (int &p_i : p) cin >> p_i;

		vector<int> pp(n);
		for (int i = 1; i <= n; i++) pp[i - 1] = i;

		vector<int> ppp = pp;
		reverse(ppp.begin(), ppp.end());

		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] != pp[i] && p[i] != ppp[i]) c++;
			else if (p[i] != pp[i]) a++;
			else if (p[i] != ppp[i]) b++;
		}

		if ((a + c) <= b) cout << "First" << nl;
		else if ((b + c) < a) cout << "Second" << nl;
		else cout << "Tie" << nl;
	}

	return 0;
}