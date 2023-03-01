#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> SN(N);
    for (pair<int, int> &sn : SN) cin >> sn.first >> sn.second;

    vector<pair<int, int>> SM(M);
    for (pair<int, int> &sm : SM) cin >> sm.first >> sm.second;

    int res = 0;
    int N_miles = 0;
    int M_miles = 0;
    int M_index = 0;

    for (int i = 0; i < N; i++) {
        int N_speed = SN[i].second;
        N_miles += SN[i].first;

        while (N_miles > M_miles) {
            int M_speed = SM[M_index].second;
            int speed_difference = M_speed - N_speed;
            res = max(speed_difference, res);

            if (M_miles + SM[M_index].first > N_miles) {
                int mile_difference = M_miles + SM[M_index].first - N_miles;
                M_miles = N_miles;
                SM[M_index].first = mile_difference;
            }
            else {
                M_miles += SM[M_index].first;
                M_index++;
            }
        }
    }

    cout << res << "\n";
    return 0;
}