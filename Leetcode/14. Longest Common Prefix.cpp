class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (string& str : strs) {
            string new_prefix;
            
            for (int i = 0; i < min((int) str.size(), (int) prefix.size()); i++) {
                if (str[i] == prefix[i]) {
                    new_prefix += prefix[i];
                }
                else {
                    break;
                }
            }
            
            prefix = new_prefix;
        }
        
        return prefix;
    }
};