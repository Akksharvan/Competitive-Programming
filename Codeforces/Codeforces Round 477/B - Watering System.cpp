#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n, A, B;
    cin >> n >> A >> B;

    vector<int> s(n);
    for (int &x : s) cin >> x;

    int S = accumulate(s.begin(), s.end(), 0);
    int D = s[0] * A / B;

    priority_queue<int> pq;
    for (int i = 1; i < n; i++) pq.push(s[i]);

    int ret = 0;
    while (S > D) S -= pq.top(), pq.pop(), ret++;

    cout << ret << "\n";
	return 0;
}