#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N;
    int M;

    vector<pair<int, int>> N_segments;
    vector<pair<int, int>> M_segments;

    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        int segment_miles;
        int segment_speed;

        scanf("%d%d", &segment_miles, &segment_speed);
        N_segments.push_back({segment_miles, segment_speed});
    }

    for (int i = 0; i < M; i++) {
        int segment_miles;
        int segment_speed;

        scanf("%d%d", &segment_miles, &segment_speed);
        M_segments.push_back({segment_miles, segment_speed});
    }

    int max_infraction = 0;
    int N_miles = 0;
    int M_miles = 0;
    int M_index = 0;

    for (int i = 0; i < N; i++) {
        int N_speed = N_segments[i].second;
        N_miles += N_segments[i].first;

        while (N_miles > M_miles) {
            int M_speed = M_segments[M_index].second;
            int speed_difference = M_speed - N_speed;
            max_infraction = max(speed_difference, max_infraction);

            if (M_miles + M_segments[M_index].first > N_miles) {
                int mile_difference = M_miles + M_segments[M_index].first - N_miles;
                M_miles = N_miles;
                M_segments[M_index].first = mile_difference;
            }
            else {
                M_miles += M_segments[M_index].first;
                M_index++;
            }
        }
    }

    printf("%d\n", max_infraction);
    return 0;
}