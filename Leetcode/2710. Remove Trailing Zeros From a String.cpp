class Solution {
public:
    string removeTrailingZeros(string num) {
        int i = (int) num.size() - 1;
        while (i >= 0 && num[i] == '0') i--;
        
        string s;
        for (int j = 0; j <= i; j++) s += num[j];
        
        return s;
    }
};