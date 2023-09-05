#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s, f;
	cin >> s >> f;

	queue<char> j;
	int p = 0, i = 1;

	for (const char& c : f) j.push(c);

	while (!j.empty()) {
		if (s[p] == j.front()) j.pop();
		if (j.empty()) break;

		if (p < 25) p++;
		else { p = 0; i++; }
	}

	cout << i << "\n";
	return 0;
}