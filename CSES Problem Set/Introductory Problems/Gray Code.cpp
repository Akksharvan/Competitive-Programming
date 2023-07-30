#include <bits/stdc++.h>
using namespace std;
 
void foo (int n) {
    for (int i = 0; i < (1 << n); i++) {
        bitset<32> r(i ^ (i >> 1));
        string s = r.to_string();
        cout << s.substr(32 - n) << "\n";
    }
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int N; cin >> N;
	foo(N); return 0;
}