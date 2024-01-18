class Solution {
public:
    string maximumOddBinaryNumber(string S) {
        int A = 0; for (char &c : S) if (c == '1') A++;
        A--; string R; for (int i = 0; i < A; i++) R += '1';
        for (int i = 0; i < (size(S) - (A + 1)); i++) R += '0';
        
        return (R + '1');
    }
};