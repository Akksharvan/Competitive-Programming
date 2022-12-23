#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> zodiac_years;
	zodiac_years.insert({"Ox", 0});
	zodiac_years.insert({"Tiger", 1});
	zodiac_years.insert({"Rabbit", 2});
	zodiac_years.insert({"Dragon", 3});
	zodiac_years.insert({"Snake", 4});
	zodiac_years.insert({"Horse", 5});
	zodiac_years.insert({"Goat", 6});
	zodiac_years.insert({"Monkey", 7});
	zodiac_years.insert({"Rooster", 8});
	zodiac_years.insert({"Dog", 9});
	zodiac_years.insert({"Pig", 10});
	zodiac_years.insert({"Rat", 11});

	map<int, string> year_zodiacs;
	year_zodiacs.insert({0, "Ox"});
	year_zodiacs.insert({1, "Tiger"});
	year_zodiacs.insert({2, "Rabbit"});
	year_zodiacs.insert({3, "Dragon"});
	year_zodiacs.insert({4, "Snake"});
	year_zodiacs.insert({5, "Horse"});
	year_zodiacs.insert({6, "Goat"});
	year_zodiacs.insert({7, "Monkey"});
	year_zodiacs.insert({8, "Rooster"});
	year_zodiacs.insert({9, "Dog"});
	year_zodiacs.insert({10, "Pig"});
	year_zodiacs.insert({11, "Rat"});


	map<string, int> birth_years;
	birth_years.insert({"Bessie", 0});

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string a, b, c, d, e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;

		int y = birth_years[h];
		while (y < 0) {
			y += 12;
		}

		while (y > 11) {
			y -= 12;
		}

		if (d == "next") {
			if (e == year_zodiacs[y]) {
				birth_years[a] = birth_years[h] + 12;
			}
			else if (zodiac_years[e] > y) {
				birth_years[a] = birth_years[h] + (zodiac_years[e] - y);
			}
			else {
				birth_years[a] = birth_years[h] + (12 - (y - zodiac_years[e]));
			}
		}
		else if (d == "previous") {
			if (e == year_zodiacs[y]) {
				birth_years[a] = birth_years[h] - 12;
			}
			else if (zodiac_years[e] < y) {
				birth_years[a] = birth_years[h] - (y - zodiac_years[e]);
			}
			else {
				birth_years[a] = birth_years[h] - (12 - (zodiac_years[e] - y));
			}
		}
	}

	cout << abs(birth_years["Elsie"]) << nl;
	return 0;
}