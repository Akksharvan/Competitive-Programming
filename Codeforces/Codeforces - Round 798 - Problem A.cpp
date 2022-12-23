#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		string a, b, c;
		cin >> a >> b;

		sort(rbegin(a), rend(a));
		sort(rbegin(b), rend(b));

		bool previous;
		int counter = 0;

		while (!a.empty() && !b.empty()) {
			if (counter < k) {
				if (a.back() < b.back()) {
					c.push_back(a.back());
					a.pop_back();

					if (previous) {
						counter++;
					}
					else {
						counter = 1;
						previous = true;
					}
				}
				else if (b.back() < a.back()) {
					c.push_back(b.back());
					b.pop_back();

					if (!previous) {
						counter++;
					}
					else {
						counter = 1;
						previous = false;
					}
				}
				else {
					if (previous) {
						c.push_back(b.back());
						b.pop_back();
					}
					else {
						c.push_back(a.back());
						a.pop_back();
					}

					previous = !previous;
					counter = 1;
				}
			}
			else {
				if (previous) {
					c.push_back(b.back());
					b.pop_back();
				}
				else {
					c.push_back(a.back());
					a.pop_back();
				}

				previous = !previous;
				counter = 1;
			}
		}

		cout << c << nl;
	}

	return 0;
}