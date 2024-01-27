#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int N; cin >> N; vector<pair<int, int>> A(N);
    for (auto &i : A) cin >> i.first >> i.second;
    
    sort(rbegin(A), rend(A)); vector<int> DP;

    for (auto &i : A) {
        if (lower_bound(begin(DP), end(DP), i.second) == end(DP)) DP.push_back(i.second);
        else *lower_bound(begin(DP), end(DP), i.second) = i.second;
    }
 
    cout << size(DP) << "\n";
    return 0;
}