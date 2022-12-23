#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, n;
	cin >> x >> n;

	set<int> lights;
	multiset<int> gaps;

	lights.insert(0);
	lights.insert(x);

	gaps.insert(x);
	
	for (int i = 0; i < n; i++) {
		int position;
		cin >> position;

		set<int>::iterator it_one = lights.upper_bound(position);
		set<int>::iterator it_two = it_one;
		
		it_two--;

		gaps.erase(gaps.find(*it_one - *it_two));
		gaps.insert(*it_one - position);
		gaps.insert(position - *it_two);

		lights.insert(position);

		multiset<int>::iterator it_three = gaps.end();
		it_three--;
		
		cout << *it_three << "\n";
	}

	return 0;
}
