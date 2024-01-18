class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = size(s) - 1;
        while (j >= 0 && s[j] == ' ') j--;

        for (int i = j - 1; i >= 0; i--) {
            if (s[i] == ' ') return (j - i);
        }

        return (j + 1);
    }
};