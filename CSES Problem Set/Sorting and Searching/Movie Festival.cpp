#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

struct Movie {
	int start, end;

	bool operator<(const Movie& m) const {
		if (end == m.end) {
			return start < m.start;
		}
		else {
			return end < m.end;
		}
	}
};

int main() {
	int n;
	cin >> n;

	vector<Movie> movies(n);
	for (Movie& m : movies) {
		cin >> m.start >> m.end;
	}

	sort(begin(movies), end(movies));

	int movies_watched = 1, movie_index = 1;
	Movie current_movie = movies[0];

	while (movie_index < n) {
		if (movies[movie_index].start >= current_movie.end) {
			current_movie = movies[movie_index];
			movies_watched++;
		}
		movie_index++;
	}

	cout << movies_watched << nl;
	return 0;
}