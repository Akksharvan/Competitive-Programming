#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	set<pair<int, int>> c, ac;
	for (int n = 0; n < N; n++) {
		pair<int, int> p;
		cin >> p.f >> p.s;

		queue<pair<int, int>> cc;
		c.insert(p);
		cc.push(p);

		set<pair<int, int>> v;
		while (!cc.empty()) {
			pair<int, int> cp = cc.front();
			cc.pop();

			if (v.count(cp) || (!c.count(cp) && !ac.count(cp))) {
				continue;
			}

			v.insert(cp);

			int ct = 0;
			ct += (c.count({cp.f - 1, cp.s}) || ac.count({cp.f - 1, cp.s}));
			ct += (c.count({cp.f + 1, cp.s}) || ac.count({cp.f + 1, cp.s}));
			ct += (c.count({cp.f, cp.s - 1}) || ac.count({cp.f, cp.s - 1}));
			ct += (c.count({cp.f, cp.s + 1}) || ac.count({cp.f, cp.s + 1}));

			if (ct == 3) {
				if (!c.count({cp.f - 1, cp.s})) {
					cc.push({cp.f - 1, cp.s});
					ac.insert({cp.f - 1, cp.s});
				}
				else if (!c.count({cp.f + 1, cp.s})) {
					cc.push({cp.f + 1, cp.s});
					ac.insert({cp.f + 1, cp.s});
				}
				else if (!c.count({cp.f, cp.s - 1})) {
					cc.push({cp.f, cp.s - 1});
					ac.insert({cp.f, cp.s - 1});
				}
				else if (!c.count({cp.f, cp.s + 1})) {
					cc.push({cp.f, cp.s + 1});
					ac.insert({cp.f, cp.s + 1});
				}
			}

			cc.push({cp.f - 1, cp.s});
			cc.push({cp.f + 1, cp.s});
			cc.push({cp.f, cp.s - 1});
			cc.push({cp.f, cp.s + 1});
		}

		cout << sz(ac) << nl;
		ac.clear();
	}

	return 0;
}