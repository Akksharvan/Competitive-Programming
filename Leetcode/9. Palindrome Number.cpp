class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        vector<int> xv;
        while (x != 0) {
            xv.push_back(x % 10);
            x /= 10;
        }
        
        int n = (int) xv.size();
        for (int i = 0; i < n / 2; i++) {
            if (xv[i] != xv[n - (i + 1)]) {
                return false;
            }
        }
        
        return true;
    }
};