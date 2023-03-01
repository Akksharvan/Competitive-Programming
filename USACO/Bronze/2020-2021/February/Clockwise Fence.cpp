#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define spc " "
#define sz(x) ((int) x.size())

vector<pair<int, int>> vertices_from_fence_path(string fence_path) {
	vector<pair<int, int>> vertices;
	int x = 0, y = 0;
	for (int i = 0; i < sz(fence_path); i++) {
		if (i == 0) {
			if (fence_path[i] != fence_path[sz(fence_path) - 1]) {
				vertices.push_back({x, y});
			}
		}
		else {
			if (fence_path[i] != fence_path[i - 1]) {
				vertices.push_back({x, y});
			}
		}

		if (fence_path[i] == 'E') {
			x++;
		}
		else if (fence_path[i] == 'N') {
			y++;
		}
		else if (fence_path[i] == 'W') {
			x--;
		}
		else if (fence_path[i] == 'S') {
			y--;
		}
	}

	return vertices;
}

int shoelace (vector<pair<int, int>>& vertices) {
	int component_one = 0, component_two = 0;
	for (int i = 0; i < sz(vertices); i++) {
		if (i != sz(vertices) - 1) {
			component_one += (vertices[i].first * vertices[i + 1].second);
		}
		else {
			component_one += (vertices[i].first * vertices[0].second);
		}
	}

	for (int i = 0; i < sz(vertices); i++) {
		if (i != sz(vertices) - 1) {
			component_two += (vertices[i].second * vertices[i + 1].first);
		}
		else {
			component_two += (vertices[i].second * vertices[0].first);
		}
	}

	return (component_one - component_two) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string fence_path;
		cin >> fence_path;

		vector<pair<int, int>> vertices = vertices_from_fence_path(fence_path);
		int area = shoelace(vertices);

		if (area > 0) {
			cout << "CCW" << nl;
		}
		else {
			cout << "CW" << nl;
		}
	}

	return 0;
}
