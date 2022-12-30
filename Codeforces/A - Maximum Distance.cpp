#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long int maximum_distance_squared;
    maximum_distance_squared = 0ll;
    cin >> N;

    vector<pair<int, int>> points(N);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0) {
                cin >> points[j].first;
            }
            else {
                cin >> points[j].second;
            }
        }
    }

    for (pair<int, int> point1 : points) {
        for (pair<int, int> point2 : points) {
            long long int x_distance = (point2.first - point1.first) * (point2.first - point1.first) * 1ll;
            long long int y_distance = (point2.second - point1.second) * (point2.second - point1.second) * 1ll;

            long long int distance_squared = x_distance + y_distance;
            maximum_distance_squared = max(maximum_distance_squared, distance_squared);
        }
    }

    cout << maximum_distance_squared << "\n";
}