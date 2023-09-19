#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> ZY;
	ZY.insert({"Ox", 0}); ZY.insert({"Tiger", 1}); ZY.insert({"Rabbit", 2});
	ZY.insert({"Dragon", 3}); ZY.insert({"Snake", 4}); ZY.insert({"Horse", 5});
	ZY.insert({"Goat", 6}); ZY.insert({"Monkey", 7}); ZY.insert({"Rooster", 8});
	ZY.insert({"Dog", 9}); ZY.insert({"Pig", 10}); ZY.insert({"Rat", 11});

	map<int, string> YZ;
	YZ.insert({0, "Ox"}); YZ.insert({1, "Tiger"}); YZ.insert({2, "Rabbit"});
	YZ.insert({3, "Dragon"}); YZ.insert({4, "Snake"}); YZ.insert({5, "Horse"});
	YZ.insert({6, "Goat"}); YZ.insert({7, "Monkey"}); YZ.insert({8, "Rooster"});
	YZ.insert({9, "Dog"}); YZ.insert({10, "Pig"}); YZ.insert({11, "Rat"});


	map<string, int> BY;
	BY.insert({"Bessie", 0});

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		string a, b, c, d, e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;

		int y = BY[h];
		while (y < 0) y += 12;
		while (y > 11) y -= 12;

		if (d == "next") {
			if (e == YZ[y]) BY[a] = BY[h] + 12;
			else if (ZY[e] > y) BY[a] = BY[h] + (ZY[e] - y);
			else BY[a] = BY[h] + (12 - (y - ZY[e]));
		}
		else if (d == "previous") {
			if (e == YZ[y]) BY[a] = BY[h] - 12;
			else if (ZY[e] < y) BY[a] = BY[h] - (y - ZY[e]);
			else BY[a] = BY[h] - (12 - (ZY[e] - y));
		}
	}

	cout << abs(BY["Elsie"]) << "\n";
	return 0;
}