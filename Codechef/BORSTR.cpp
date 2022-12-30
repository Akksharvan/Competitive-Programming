#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define nl "\n"
#define spc " "

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	
	while (T--) {
	    int N;
	    string S;
	    cin >> N >> S;
	    
	    int l = 0, r = 0, ans = 0, ct = 0;
	    set<char> cc;
	    
	    while (l < N) {
	        while (r < N) {
	            r++;
	            
	            if (r == N || S[r] != S[l]) {
	                break;
	            }
	        }
	        
	        int temp_ans = r - l;
	        if (temp_ans > ans) {
	            ans = temp_ans;
	            ct = 0;
	            
	            cc.clear();
	            cc.insert(S[l]);
	        }
	        else if (temp_ans == ans) {
	            if (cc.count(S[l])) {
	                ct = 1;
	            }
	            else {
	                cc.insert(S[l]);
	            }
	        }
	        
	        l = r;
	    }
	    
	    if (ct) {
	        cout << ans << nl;
	    }
	    else {
	        cout << ans - 1 << nl;
	    }
	}
	return 0;
}