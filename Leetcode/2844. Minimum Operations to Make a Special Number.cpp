class Solution {
public:
    int minimumOperations(string num) {
        int R = size(num);
        if (num.find('0') != string::npos) R = size(num) - 1;
        
        for (int i = size(num) - 1; i >= 0; i--) {
            if (num[i] != '0') continue;
            while ((i - 1) >= 0) { i--; if (num[i] == '0') R = min(R, (int) size(num) - 2 - i); } 
        }
        
        for (int i = size(num) - 1; i >= 0; i--) {
            if (num[i] != '5') continue;
            while ((i - 1) >= 0) { i--; if (num[i] == '2') R = min(R, (int) size(num) - 2 - i); } 
        }
        
        for (int i = size(num) - 1; i >= 0; i--) {
            if (num[i] != '0') continue;
            while ((i - 1) >= 0) { i--; if (num[i] == '5') R = min(R, (int) size(num) - 2 - i); } 
        }
        
        for (int i = size(num) - 1; i >= 0; i--) {
            if (num[i] != '5') continue;
            while ((i - 1) >= 0) { i--; if (num[i] == '7') R = min(R, (int) size(num) - 2 - i); } 
        }
        
        return R;
    }
};